#include <utils/SysDirs.h>
#include <utils/Log.h>
#include <cutils/memory.h>
#include <stdlib.h>
#include <string.h>

#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>

namespace android {

bool MkDir(const std::string dir, mode_t m) {
	char tmp[256];
	char *p = NULL;
	size_t len;

	strlcpy(tmp, dir.c_str(), sizeof(tmp));
	len = strlen(tmp);
	if(tmp[len - 1] == '/')
		tmp[len - 1] = 0;
	for(p = tmp + 1; *p; p++)
		if(*p == '/') {
			*p = 0;
			if (mkdir(tmp, m) != 0  && errno != EEXIST)
				return false;
			*p = '/';
		}
	if (mkdir(tmp, m) != 0  && errno != EEXIST)
		return false;
	return true;
}


static bool DirectoryExists(const char* name) {
	struct stat st;
	if (stat(name, &st) == 0) {
		return S_ISDIR(st.st_mode);  // TODO: Deal with symlinks?
	} else {
		return false;
	}
}


std::string GetAndroidHome() {
	const char* home = getenv("HOME");
	if (home == NULL || !DirectoryExists(home)) {
		ALOGE("HOME directory doesn't exist");
		return "";
	}
	std::string android_home(home);
	android_home += "/.android";
	return android_home;
}

static std::string GetAndroidDir(bool target, const char *env, const char *subdir) {
	const char* dir = getenv(env);
	if (dir != NULL) {
		if (!DirectoryExists(dir)) {
			ALOGE("ANDROID_ROOT does not exist $ANDROID_ROOT=%s", dir);
			return "";
		}
		return dir;
	}
	if (target) {
		if (DirectoryExists(dir)) {
			dir = subdir;
			return dir;
		} 
		ALOGE("%s not set and %s does not exist", env, dir);
		return "";
	} else {
		std::string host_dir = GetAndroidHome() + subdir;
		if (!MkDir(host_dir)) {
			ALOGE("Failed to create %s directory", host_dir.c_str());
			return "";
		}
		return host_dir;
	}
}

std::string GetAndroidRoot(bool target) {
	return GetAndroidDir(target, "ANDROID_ROOT", "/system");
}

std::string GetAndroidData(bool target) {
	return GetAndroidDir(target, "ANDROID_DATA", "/data");
}


} // namespace android
