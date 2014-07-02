project (log)
find_package (Threads REQUIRED)

include_directories ("${PROJECT_SOURCE_DIR}/../include")

set (SRC_LIST logd_write.c
		uio.c
		log_read.c)

set (HOST_SRC_LIST fake_log_device.c)

add_definitions (-DFAKE_LOG_DEVICE=1)

add_library (${PROJECT_NAME} SHARED ${SRC_LIST} ${HOST_SRC_LIST})
SET_TARGET_PROPERTIES (${PROJECT_NAME} PROPERTIES LINK_FLAGS -Wl,--no-undefined)
target_link_libraries (${PROJECT_NAME} ${CMAKE_THREAD_LIBS_INIT})


install (TARGETS ${PROJECT_NAME} DESTINATION ${INSTALL_LIB_DIR})
install (DIRECTORY ${PROJECT_SOURCE_DIR}/../include/log DESTINATION ${INSTALL_INCLUDE_DIR} FILES_MATCHING PATTERN "*.h")



