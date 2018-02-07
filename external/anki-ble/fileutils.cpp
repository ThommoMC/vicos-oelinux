/**
 * File: fileutils.cpp
 *
 * Author: seichert
 * Created: 1/19/2018
 *
 * Description: Routines for working with files
 *
 * Copyright: Anki, Inc. 2018
 *
 **/

#include "fileutils.h"
#include "log.h"
#include <fstream>

namespace Anki {

int WriteFileAtomically(const std::string& path,
                        const std::string& data,
                        mode_t mode,
                        uid_t owner,
                        gid_t group)
{
  std::string tmpPath = path + ".tmp";

  {
    std::ofstream ofstrm(tmpPath, std::ios::binary | std::ios::out | std::ios::trunc);
    if (!ofstrm.is_open()) {
      logi("Failed to open '%s'", tmpPath.c_str());
      return -1;
    }

    ofstrm << data;
  }

  int rc = chmod(tmpPath.c_str(), mode);
  if (rc) {
    logi("Error chmoding '%s' errno = %d", tmpPath.c_str(), errno);
    return rc;
  }
  rc = chown(tmpPath.c_str(), owner, group);
  if (rc) {
    logi("Error chowning '%s' errno = %d", tmpPath.c_str(), errno);
    return rc;
  }
  rc = rename(tmpPath.c_str(), path.c_str());
  if (rc) {
    logi("Error renaming '%s' to '%s' errno = %d", tmpPath.c_str(), path.c_str(), errno);
    return rc;
  }
  return 0;
}


} // namespace Anki
