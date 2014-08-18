project(android-corelibs)

cmake_minimum_required(VERSION 2.8)
include(/usr/share/android/cmake/AndroidConfig.cmake)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")

add_subdirectory(liblog)
add_subdirectory(libcutils)
add_subdirectory(libbacktrace)
add_subdirectory(libutils)
add_subdirectory(libsparse)
add_subdirectory(libziparchive)
add_subdirectory(libzipfile)
add_subdirectory(libnativebridge)

install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/android DESTINATION ${INSTALL_INCLUDE_DIR} FILES_MATCHING PATTERN "*.h")
install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/system DESTINATION ${INSTALL_INCLUDE_DIR} FILES_MATCHING PATTERN "*.h")





