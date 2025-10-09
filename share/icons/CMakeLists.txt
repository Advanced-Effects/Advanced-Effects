
include(GetPlatformInfo)

if (OS_IS_MAC)
    install(FILES AppIcon/APP_AppIcon.icns RENAME AppIcon.icns DESTINATION ${Mscore_SHARE_NAME}${Mscore_INSTALL_NAME})

elseif(OS_IS_WIN)
    # See also windows_icons.rc

    if (WIN_PORTABLE)
        install(FILES AppIcon/APP_AppIcon.ico RENAME appicon.ico DESTINATION ${CMAKE_INSTALL_PREFIX}/../AppInfo)
        install(FILES AppIcon/APP_AppIcon_16x16.png RENAME appicon_16.png DESTINATION ${CMAKE_INSTALL_PREFIX}/../AppInfo)
        install(FILES AppIcon/APP_AppIcon_32x32.png RENAME appicon_32.png DESTINATION ${CMAKE_INSTALL_PREFIX}/../AppInfo)
        install(FILES AppIcon/APP_AppIcon_128x128.png RENAME appicon_128.png DESTINATION ${CMAKE_INSTALL_PREFIX}/../AppInfo)
    endif()

elseif(OS_IS_LIN)
    foreach(SIZE 16 24 32 48 64 96 128 512)
        install(FILES AppIcon/APP_AppIcon_${SIZE}x${SIZE}.png 
                RENAME app${MUSE_APP_INSTALL_SUFFIX}.png 
                DESTINATION share/icons/hicolor/${SIZE}x${SIZE}/apps)
    endforeach()

    # Note: Must now run "gtk-update-icon-cache" to set the new icons.
endif()