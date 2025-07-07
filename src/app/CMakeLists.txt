###########################################
# Library list
###########################################

set(LIB_LIST
    ${QT_LIBRARIES}

    ae::app
    ae::project_file
    ae::ui
    ae::uicomponents
    ae::appshell
)

###########################################
# Setup executable
###########################################

qt_add_executable(${CMAKE_PROJECT_NAME}
    main.cpp
    assets/assets.qrc
)

###########################################
# Link libraries
###########################################

target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE ${LIB_LIST})
