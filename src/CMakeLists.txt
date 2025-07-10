# Library, should be first to work
# Contains core libraries required for the program to work,
# and the UI components library
add_subdirectory(library)

# Appshell (Application GUI)
add_subdirectory(appshell)


###########################################
# App (main executable)
###########################################

set(LIB_LIST
    ${QT_LIBRARIES}
    muse::global

    ae::app
    ae::project_file

    muse::ui
    muse::uicomponents
    muse::dockwindow
    ae::appshell
)

qt_add_executable(${CMAKE_PROJECT_NAME}
    main.cpp
    ../assets/assets.qrc
)

target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE ${LIB_LIST})
