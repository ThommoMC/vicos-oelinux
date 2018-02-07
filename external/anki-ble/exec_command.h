/**
 * File: exec_command.h
 *
 * Author: seichert
 * Created: 1/19/2018
 *
 * Description: Execute a command and return results
 *
 * Copyright: Anki, Inc. 2018
 *
 **/


#pragma once
#include <functional>
#include <string>
#include <vector>

namespace Anki {

using ExecCommandCallback = std::function<void (int rc, const std::string& output)>;

void ExecCommandInBackground(const std::vector<std::string>& args, ExecCommandCallback callback);

int ExecCommand(const std::vector<std::string>& args, std::string& output);

void CancelBackgroundCommands();

} // namespace Anki
