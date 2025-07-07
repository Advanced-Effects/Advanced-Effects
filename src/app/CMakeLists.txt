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

target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE
    ${QT_LIBRARIES}
    muse::ui
    muse::uicomponents
    ae::app
    ae::project_file
    ae::appshell
)
