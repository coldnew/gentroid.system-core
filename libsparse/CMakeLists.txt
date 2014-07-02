project (sparse)
find_package (ZLIB REQUIRED)
include_directories (${CMAKE_CURRENT_SOURCE_DIR}/include ${CMAKE_CURRENT_SOURCE_DIR}/../include ${ZLIB_INCLUDE_DIR} ${ZLIB_INCLUDE_DIR})

set(SRC_LIST backed_block.c
      	output_file.c
        sparse.c
        sparse_crc32.c
        sparse_err.c
        sparse_read.c)

add_library (${PROJECT_NAME} SHARED ${SRC_LIST})
SET_TARGET_PROPERTIES (${PROJECT_NAME} PROPERTIES LINK_FLAGS -Wl,--no-undefined)
target_link_libraries (${PROJECT_NAME} ${ZLIB_LIBRARIES})

install (TARGETS ${PROJECT_NAME} DESTINATION ${INSTALL_LIB_DIR})
install (DIRECTORY ${PROJECT_SOURCE_DIR}include/${PROJECT_NAME} DESTINATION ${INSTALL_INCLUDE_DIR}/${PROJECT_NAME} FILES_MATCHING PATTERN "*.h")
