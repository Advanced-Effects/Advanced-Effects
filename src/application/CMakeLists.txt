###########################################
# We define the target first to set the include paths
###########################################

qt_add_executable(${CMAKE_PROJECT_NAME}
    main.cpp
    ../../assets/assets.qrc
)

###########################################
# Set include paths
###########################################

target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE ${MUSE_FRAMEWORK_SRC_PATH}/library/)
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

    muse::ui
    muse::uicomponents
    muse::dockwindow

    ae::services
    ae::appshell
)

target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE ${LIB_LIST})
