/**
 * File: fileutils.h
 *
 * Author: seichert
 * Created: 1/19/2018
 *
 * Description: Routines for working with files
 *
 * Copyright: Anki, Inc. 2018
 *
 **/


#pragma once

#include <sys/stat.h>
#include <unistd.h>
#include <string>


namespace Anki {

const uid_t kRootUid = 0;
const gid_t kRootGid = 0;
const mode_t kModeUserReadWrite = (S_IRUSR | S_IWUSR);
const mode_t kModeUserGroupReadWrite = (kModeUserReadWrite | S_IRGRP | S_IWGRP);

int WriteFileAtomically(const std::string& path,
                        const std::string& data,
                        mode_t mode = kModeUserGroupReadWrite,
                        uid_t owner = kRootUid,
                        gid_t group = kRootGid);


} // namespace Anki
