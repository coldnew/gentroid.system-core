project (nativebridge)
include_directories (${PROJECT_SOURCE_DIR}/../include)

add_library (${PROJECT_NAME} SHARED native_bridge.cc)
SET_TARGET_PROPERTIES (${PROJECT_NAME} PROPERTIES LINK_FLAGS -Wl,--no-undefined)
target_link_libraries (${PROJECT_NAME} ${CMAKE_DL_LIBS})

install (TARGETS ${PROJECT_NAME} DESTINATION ${INSTALL_LIB_DIR})
install (DIRECTORY ${PROJECT_SOURCE_DIR}/../include/${PROJECT_NAME} DESTINATION ${INSTALL_INCLUDE_DIR} FILES_MATCHING PATTERN "*.h")
