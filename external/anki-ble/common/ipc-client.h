/*
 * File: ipc-client.h
 *
 * Author: seichert
 * Created: 2/5/2018
 *
 * Description: IPC Client for ankibluetoothd
 *
 * Copyright: Anki, Inc. 2018
 *
 **/

#pragma once

#include "include_ev.h"
#include "ipc.h"

#include <deque>
#include <mutex>
#include <vector>

namespace Anki {
namespace BluetoothDaemon {

class IPCClient : public IPCEndpoint {
 public:
  IPCClient(struct ev_loop* loop);
  ~IPCClient();
  bool Connect();
  void SendIPCMessageToServer(const IPCMessageType type) {
    SendIPCMessageToServer(type, 0, nullptr);
  }
  void SendIPCMessageToServer(const IPCMessageType type,
                              uint32_t length,
                              uint8_t* val) { SendMessageToPeer(type, length, val); }
  bool IsConnected() { return !peers_.empty(); }
  void SendMessage(const int connection_id,
                   const std::string& characteristic_uuid,
                   const bool reliable,
                   const std::vector<uint8_t>& value);
  void Disconnect(const int connection_id);

 protected:
  virtual void OnReceiveIPCMessage(const int sockfd,
                                   const IPCMessageType type,
                                   const std::vector<uint8_t>& data);
  virtual void OnInboundConnectionChange(int connection_id, int connected) { }
  virtual void OnReceiveMessage(const int connection_id,
                                const std::string& characteristic_uuid,
                                const std::vector<uint8_t>& value) {}

 private:
  void ConnectWatcherCallback(ev::io& w, int revents);
  void OnConnect();

  ev::io* connect_watcher_;
};

} // namespace BluetoothDaemon
} // namespace Anki

