message("-- Installing share/locales")
add_subdirectory(locales)

message("-- Installing share/workspaces")
install (DIRECTORY
    workspaces
    DESTINATION ${AU4_SHARE_NAME}${AU4_INSTALL_NAME}
    PATTERN ".*" EXCLUDE
    )
message("   to ${CMAKE_BINARY_DIR}/${AU4_SHARE_NAME}${AU4_INSTALL_NAME}/workspaces")
