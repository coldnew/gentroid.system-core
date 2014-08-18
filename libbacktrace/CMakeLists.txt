project (backtrace)
find_package (Threads REQUIRED)
find_package (Unwind REQUIRED)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")

string (TOLOWER ${CMAKE_SYSTEM_PROCESSOR} ARCH_SUFFIX)

find_library (UNWIND_LIBRARY unwind PATHS ${UNWIND_LIBRARY_DIRS} NO_DEFAULT_PATH)
find_library (UNWIND_LIBRARY_PTRACE unwind-ptrace PATHS ${UNWIND_LIBRARY_DIRS} NO_DEFAULT_PATH)
find_library (UNWIND_LIBRARY_ARCH unwind-${ARCH_SUFFIX} PATHS ${UNWIND_LIBRARY_DIRS} NO_DEFAULT_PATH)

include_directories (${PROJECT_SOURCE_DIR} ${PROJECT_SOURCE_DIR}/../include ${UNWIND_INCLUDE_DIRS})

set (SRC_LIST BacktraceImpl.cpp
	BacktraceMap.cpp
	BacktraceThread.cpp
	thread_utils.c
	UnwindCurrent.cpp
	UnwindMap.cpp 
	UnwindPtrace.cpp)


add_library (${PROJECT_NAME} SHARED ${SRC_LIST})
SET_TARGET_PROPERTIES (${PROJECT_NAME} PROPERTIES LINK_FLAGS -Wl,--no-undefined)
target_link_libraries (${PROJECT_NAME} cutils log ${UNWIND_LIBRARY} ${UNWIND_LIBRARY_PTRACE} ${UNWIND_LIBRARY_ARCH} ${CMAKE_THREAD_LIBS_INIT})

install (TARGETS ${PROJECT_NAME} DESTINATION ${INSTALL_LIB_DIR})
install (DIRECTORY ${PROJECT_SOURCE_DIR}/../include/${PROJECT_NAME} DESTINATION ${INSTALL_INCLUDE_DIR} FILES_MATCHING PATTERN "*.h")



