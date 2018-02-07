/**
 * File: exec_command.cpp
 *
 * Author: seichert
 * Created: 1/19/2018
 *
 * Description: Execute a command and return results
 *
 * Copyright: Anki, Inc. 2018
 *
 **/

#include "exec_command.h"
#include "fork_and_exec.h"
#include "taskExecutor.h"

#include <sstream>

namespace Anki {

static TaskExecutor* sBackgroundTaskExecutor;
static bool sBackgroundCommandsCancelled = false;

int ExecCommand(const std::vector<std::string>& args, std::string& output)
{
  std::ostringstream oss;

  int rc = ForkAndExec(args, oss);

  output = oss.str();

  return rc;

}

void ExecCommandInBackground(const std::vector<std::string>& args,
                             ExecCommandCallback callback,
                             long delayMillis)
{
  sBackgroundCommandsCancelled = false;
  auto f = [args, callback]() {
    std::string output;
    int rc = sBackgroundCommandsCancelled ? -1 : ExecCommand(args, output);
    if (callback) {
      callback(rc, output);
    }
  };
  if (!sBackgroundTaskExecutor) {
    sBackgroundTaskExecutor = new TaskExecutor();
  }
  if (delayMillis > 0L) {
    auto when = std::chrono::steady_clock::now() + std::chrono::milliseconds(delayMillis);
    sBackgroundTaskExecutor->WakeAfter(f, when);
  } else {
    sBackgroundTaskExecutor->Wake(f);
  }
}

void CancelBackgroundCommands()
{
  sBackgroundCommandsCancelled = true;
  KillChildProcess();
  if (sBackgroundTaskExecutor) {
    delete sBackgroundTaskExecutor; sBackgroundTaskExecutor = nullptr;
  }
}

} // namespace Anki
