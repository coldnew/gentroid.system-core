project (ziparchive)
find_package (ZLIB REQUIRED)

include_directories (${PROJECT_SOURCE_DIR}/../include ${ZLIB_INCLUDE_DIR})
add_definitions (-DLIBUTILS_NATIVE=1 -Wno-multichar)

add_library (${PROJECT_NAME} SHARED zip_archive.cc)
SET_TARGET_PROPERTIES (${PROJECT_NAME} PROPERTIES LINK_FLAGS -Wl,--no-undefined)
target_link_libraries (${PROJECT_NAME} utils ${ZLIB_LIBRARIES})

install (TARGETS ${PROJECT_NAME} DESTINATION ${INSTALL_LIB_DIR})
install (DIRECTORY ${PROJECT_SOURCE_DIR}/../include/${PROJECT_NAME} DESTINATION ${INSTALL_INCLUDE_DIR} FILES_MATCHING PATTERN "*.h")
