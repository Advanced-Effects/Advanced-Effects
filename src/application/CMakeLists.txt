###########################################
# We define the target first to set the include paths
###########################################

qt_add_executable(${CMAKE_PROJECT_NAME}
    main.cpp
    cmdline.h
    cmdline.cpp
    app.h
    app.cpp
    ../../assets/assets.qrc
)

###########################################
# Set include paths
###########################################

target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_LIST_DIR}/../library/)
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE ${MUSE_FRAMEWORK_SRC_PATH}/framework/)
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE ${MUSE_FRAMEWORK_SRC_PATH}/framework/global/)

###########################################
# App (main executable)
###########################################

set(LIB_LIST
    ${QT_LIBRARIES}
    muse::global

    ae::app
    ae::project_file

    muse::accessibility
    muse::actions
    muse::audio
    muse::diagnostics
    muse::extensions
    muse::languages
    muse::learn
    muse::midi
    muse::mpe
    muse::multiinstances
    muse::network
    muse::shortcuts
    muse::tours
    muse::update
    muse::workspace

    muse::ui
    muse::uicomponents
    muse::dockwindow

    ae::services
    ae::context
    ae::appshell
)

target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE ${LIB_LIST})
