project (utils)
include_directories (${PROJECT_SOURCE_DIR}/../include)

set (SRC_LIST	BasicHashtable.cpp
	BlobCache.cpp
	CallStack.cpp
	FileMap.cpp
	JenkinsHash.cpp
	LinearAllocator.cpp
	LinearTransform.cpp
	Log.cpp
	Printer.cpp
	PropertyMap.cpp
	ProcessCallStack.cpp
	PropertyMap.cpp
	RefBase.cpp
	SharedBuffer.cpp
	Static.cpp
	StopWatch.cpp
	String8.cpp
	String16.cpp
	SystemClock.cpp
	Threads.cpp 
	Timers.cpp 
	Tokenizer.cpp 
	Unicode.cpp
	VectorImpl.cpp
	misc.cpp
	Looper.cpp
	SysDirs.cpp)

add_definitions (-DLIBUTILS_NATIVE=1 -Wno-multichar)

add_library (${PROJECT_NAME} SHARED ${SRC_LIST})
SET_TARGET_PROPERTIES (${PROJECT_NAME} PROPERTIES LINK_FLAGS -Wl,--no-undefined)
target_link_libraries (${PROJECT_NAME} cutils backtrace log)

install (TARGETS ${PROJECT_NAME} DESTINATION ${INSTALL_LIB_DIR})
install (DIRECTORY ${PROJECT_SOURCE_DIR}/../include/${PROJECT_NAME} DESTINATION ${INSTALL_INCLUDE_DIR} FILES_MATCHING PATTERN "*.h")
