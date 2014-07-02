project (cutils)
find_package (Threads REQUIRED)

include_directories ("${PROJECT_SOURCE_DIR}/../include")

set (SRC_LIST_COMMON hashmap.c
	atomic.c
	native_handle.c
	socket_inaddr_any_server.c
	socket_local_client.c
	socket_local_server.c
	socket_loopback_client.c
	socket_loopback_server.c
	socket_network_client.c
	sockets.c
	config_utils.c
	cpu_info.c
	load_file.c
	open_memstream.c
	strdup16to8.c
	strdup8to16.c
	record_stream.c
	process_name.c
	threads.c
	sched_policy.c
	iosched_policy.c
	str_parms.c
	properties.c
	multiuser.c
	fs.c
	memory.c)

set (SRC_LIST_TARGET android_reboot.c
        ashmem-dev.c
        debugger.c
        klog.c
        mq.c
        partition_utils.c
        qtaguid.c
		trace.c
        uevent.c)

set (SRC_LIST_HOST ashmem-host.c 
		dlmalloc_stubs.c)

if (CMAKE_SYSTEM_PROCESSOR STREQUAL "x86")
	set(SRC_LIST_ARCH arch-x86/android_memset16.S arch-x86/android_memset32.S)
	add_definitions(-DHAVE_MEMSET16 -DHAVE_MEMSET32)
elseif (CMAKE_SYSTEM_PROCESSOR STREQUAL "x86_64")
	set(SRC_LIST_ARCH   arch-x86_64/android_memset16_SSE2-atom.S arch-x86_64/android_memset32_SSE2-atom.S arch-arm64/android_memset.S)
	add_definitions(-DHAVE_MEMSET16 -DHAVE_MEMSET32)
elseif (CMAKE_SYSTEM_PROCESSOR STREQUAL "arm")
	set(SRC_LIST_ARCH arch-arm/memset32.S)
endif ()

add_library (${PROJECT_NAME} SHARED ${SRC_LIST_COMMON} ${SRC_LIST_ARCH} ${SRC_LIST_HOST})
SET_TARGET_PROPERTIES (${PROJECT_NAME} PROPERTIES LINK_FLAGS -Wl,--no-undefined)
target_link_libraries (${PROJECT_NAME} log ${CMAKE_THREAD_LIBS_INIT})

install (TARGETS ${PROJECT_NAME} DESTINATION ${INSTALL_LIB_DIR})
install (DIRECTORY ${PROJECT_SOURCE_DIR}/../include/${PROJECT_NAME} DESTINATION ${INSTALL_INCLUDE_DIR} FILES_MATCHING PATTERN "*.h")



