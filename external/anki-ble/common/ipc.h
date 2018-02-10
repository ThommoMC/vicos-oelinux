/**
 * File: ipc.h
 *
 * Author: seichert
 * Created: 2/5/2018
 *
 * Description: IPC for ankibluetoothd
 *
 * Copyright: Anki, Inc. 2018
 *
 **/

#pragma once

#include "include_ev.h"
#include "taskExecutor.h"

#include <deque>
#include <mutex>
#include <string>
#include <vector>

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>

namespace Anki {
namespace BluetoothDaemon {
const std::string kSocketName("/data/misc/bluetooth/abtd.socket");
const char kIPCMessageMagic[4] = {'i', 'p', 'c', 'f'};
const uint32_t kIPCMessageVersion = 1;
const size_t kUUIDSize = 37;

enum class IPCMessageType {
  Invalid = 0,
    Ping,
    OnPingResponse,
    SendMessage,
    OnInboundConnectionChange,
    OnReceiveMessage,
    Disconnect,
};

typedef struct __attribute__ ((__packed__)) IPCMessage {
  char magic[4];
  uint32_t version;
  IPCMessageType type;
  uint32_t length;
} IPCMessage;

typedef struct __attribute__ ((__packed__)) SendMessageArgs {
  int connection_id;
  char characteristic_uuid[kUUIDSize];
  bool reliable;
  uint32_t length;
  uint8_t value[];
} SendMessageArgs;

typedef struct __attribute__ ((__packed__)) OnInboundConnectionChangeArgs {
  int connection_id;
  int connected;
} OnInboundConnectionChangeArgs;

typedef struct __attribute__ ((__packed__)) OnReceiveMessageArgs {
  int connection_id;
  char characteristic_uuid[kUUIDSize];
  uint32_t length;
  uint8_t value[];
} OnReceiveMessageArgs;

typedef struct __attribute__ ((__packed__)) DisconnectArgs {
  int connection_id;
} DisconnectArgs;

class IPCEndpoint {
 public:
  IPCEndpoint(struct ev_loop* loop);
  ~IPCEndpoint();
  bool IsSocketValid() const { return (sockfd_ != -1); }
  void SendMessageToAllPeers(const IPCMessageType type,
                             uint32_t length,
                             uint8_t* val);
  void SendMessageToPeer(const IPCMessageType type,
                         uint32_t length,
                         uint8_t* val)
  {
    SendMessageToPeer(sockfd_, type, length, val);
  }
  void SendMessageToPeer(const int fd,
                         const IPCMessageType type,
                         uint32_t length,
                         uint8_t* val);

 protected:
  class PeerState {
   public:
    PeerState(ev::io* read_write_watcher, TaskExecutor* task_executor)
        : mutex_(new std::mutex())
        , read_write_watcher_(read_write_watcher)
        , task_executor_(task_executor) { }
    ~PeerState();
    int GetFD() const;
    bool IsQueueEmpty();
    void AddMessageToQueue(const std::vector<uint8_t>& message);
    std::vector<uint8_t> GetMessageAtFrontOfQueue();
    void EraseMessageFromFrontOfQueue();
   private:
    std::mutex* mutex_;
    ev::io* read_write_watcher_;
    std::deque<std::vector<uint8_t>> outgoing_queue_;
    TaskExecutor* task_executor_;
  };
  void AddPeerByFD(const int fd);
  std::vector<PeerState>::iterator FindPeerByFD(const int fd);
  void RemovePeerByFD(const int fd);
  void CloseSocket();
  void ReceiveMessage() { ReceiveMessage(sockfd_); }
  void ReceiveMessage(const int sockfd);
  void SendQueuedMessagesToPeer(const int sockfd);
  virtual void OnReceiveError(const int sockfd);
  virtual void OnPeerClose(const int sockfd);
  virtual void OnReceiveIPCMessage(const int sockfd,
                                   const IPCMessageType type,
                                   const std::vector<uint8_t>& data) {}
  virtual void OnSendError(const int sockfd, const int error);
  void ReadWriteWatcherCallback(ev::io& w, int revents);

  struct ev_loop* loop_;
  TaskExecutor* task_executor_;
  int sockfd_;
  struct sockaddr_un addr_;
  std::vector<PeerState> peers_;
};

} // namespace BluetoothDaemon
} // namespace Anki

