/*
 * Copyright (C) 2005 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef ANDROID_SYSDIRS_H
#define ANDROID_SYSDIRS_H
#include <string>
#include <sys/types.h>

namespace android {

bool MkDir(const std::string dir, mode_t m = 0700); 

#ifdef HAVE_ANDROID_OS
	std::string GetAndroidRoot(bool target = true);
	std::string GetAndroidData(bool target = true);
#else
    std::string GetAndroidRoot(bool target = false);
	std::string GetAndroidData(bool target = false);
#endif


} // namespace android
#endif // ANDROID_SYSDIRS_H
