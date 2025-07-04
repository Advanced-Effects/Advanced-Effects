cmake_minimum_required(VERSION 3.20)

project(AdvancedEffects VERSION 0.8 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

string(TIMESTAMP CURRENT_TIMESTAMP "%s" UTC)
set(APP_NAME ${CMAKE_PROJECT_NAME})
set(APP_VERSION ${CMAKE_PROJECT_VERSION})
set(APP_VERSION_CODE ${TIMESTAMP})

################################################################################

message(STATUS "[CMAKE]   CMAKE_VERSION             = ${CMAKE_VERSION}")
message(STATUS "[CMAKE]   CMAKE_PREFIX_PATH         = ${CMAKE_PREFIX_PATH}")
message(STATUS "[SYSTEM]  (HOST) SYSTEM NAME        = ${CMAKE_HOST_SYSTEM_NAME}")
message(STATUS "[SYSTEM]  (HOST) SYSTEM VERSION     = ${CMAKE_HOST_SYSTEM_VERSION}")
message(STATUS "[SYSTEM]  (TARGET) SYSTEM NAME      = ${CMAKE_SYSTEM_NAME}")
message(STATUS "[SYSTEM]  (TARGET) SYSTEM VERSION   = ${CMAKE_SYSTEM_VERSION}")
message(STATUS "[PROJECT] SOURCE_DIR                = ${CMAKE_SOURCE_DIR}")
message(STATUS "[PROJECT] BUILD_TYPE                = ${CMAKE_BUILD_TYPE}")
message(STATUS "[PROJECT] TOOLCHAIN_FILE            = ${CMAKE_TOOLCHAIN_FILE}")
message(STATUS "[PROJECT] QT_HOST_PATH              = ${QT_HOST_PATH}")

################################################################################

find_package(Qt6 REQUIRED COMPONENTS Core Gui Svg Qml Quick QuickControls2)
find_package(Qt6 REQUIRED COMPONENTS LinguistTools)

qt_standard_project_setup(REQUIRES 6.9
                          I18N_SOURCE_LANGUAGE en
                          I18N_TRANSLATED_LANGUAGES fr)

###############################################################################

# Qt policies: https://doc.qt.io/qt-6/qt-cmake-policies.html

# set ':/qt/qml/' as the default resource prefix for QML modules
qt_policy(SET QTP0001 NEW)
qt_policy(SET QTP0002 NEW)
qt_policy(SET QTP0003 NEW) # Qt 6.7
# Extra directories with QML files in a QML module need extra qmldir files
qt_policy(SET QTP0004 NEW) # Qt 6.8

###############################################################################

# Set app icons
if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    set(app_icon_windows "${CMAKE_SOURCE_DIR}/assets/windows/${CMAKE_PROJECT_NAME}.rc")
elseif(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    set(app_icon_macos "${CMAKE_SOURCE_DIR}/assets/macos/${CMAKE_PROJECT_NAME}.icns")
endif()

################################################################################

set(UI_COMPONENTS_SRC src/Muse/uicomponents)

set(UI_COMPONENTS_QML_IMPORT ${UI_COMPONENTS_SRC}/qml )
set(UI_COMPONENTS_QMLAPI_IMPORT ${UI_COMPONENTS_SRC}/api )

################################################################################

qt_add_executable(${CMAKE_PROJECT_NAME}
    src/main.cpp
    assets/assets.qrc
    ${app_icon_windows}
    ${app_icon_macos}
)

# This was the missing piece of shit to get UiComponents to be linked to the main executable!
qt_add_library(UiComponents STATIC)
qt_add_qml_module(UiComponents
    URI "Muse.UiComponents"
    VERSION 1.0
    NO_PLUGIN
    QML_FILES
        ${UI_COMPONENTS_SRC}/api/MuseApi/Controls/qmldir
        ${UI_COMPONENTS_SRC}/qml/Muse/UiComponents/Border.qml
        ${UI_COMPONENTS_SRC}/qml/Muse/UiComponents/ButtonBox.qml
        ${UI_COMPONENTS_SRC}/qml/Muse/UiComponents/CheckBox.qml
        ${UI_COMPONENTS_SRC}/qml/Muse/UiComponents/ColorPicker.qml
        ${UI_COMPONENTS_SRC}/qml/Muse/UiComponents/ContextMenuLoader.qml
        ${UI_COMPONENTS_SRC}/qml/Muse/UiComponents/ExpandableBlank.qml
        ${UI_COMPONENTS_SRC}/qml/Muse/UiComponents/ExpandableBlankSection.qml
        ${UI_COMPONENTS_SRC}/qml/Muse/UiComponents/FilePicker.qml
        ${UI_COMPONENTS_SRC}/qml/Muse/UiComponents/FlatButton.qml
        ${UI_COMPONENTS_SRC}/qml/Muse/UiComponents/FlatButtonMenuIndicatorTriangle.qml
        ${UI_COMPONENTS_SRC}/qml/Muse/UiComponents/FlatRadioButton.qml
        ${UI_COMPONENTS_SRC}/qml/Muse/UiComponents/FlatRadioButtonList.qml
        ${UI_COMPONENTS_SRC}/qml/Muse/UiComponents/FlatToggleButton.qml
        ${UI_COMPONENTS_SRC}/qml/Muse/UiComponents/FocusableControl.qml
        ${UI_COMPONENTS_SRC}/qml/Muse/UiComponents/FocusableItem.qml
        ${UI_COMPONENTS_SRC}/qml/Muse/UiComponents/GradientRectangle.qml
        ${UI_COMPONENTS_SRC}/qml/Muse/UiComponents/GridViewSectional.qml
        ${UI_COMPONENTS_SRC}/qml/Muse/UiComponents/IncrementalPropertyControl.qml
        ${UI_COMPONENTS_SRC}/qml/Muse/UiComponents/InfoPanel.qml
        ${UI_COMPONENTS_SRC}/qml/Muse/UiComponents/ItemWithDropShadow.qml
        ${UI_COMPONENTS_SRC}/qml/Muse/UiComponents/ListItemBlank.qml
        ${UI_COMPONENTS_SRC}/qml/Muse/UiComponents/MenuButton.qml
        ${UI_COMPONENTS_SRC}/qml/Muse/UiComponents/NavigationFocusBorder.qml
        ${UI_COMPONENTS_SRC}/qml/Muse/UiComponents/NumberInputField.qml
        ${UI_COMPONENTS_SRC}/qml/Muse/UiComponents/PageIndicator.qml
        ${UI_COMPONENTS_SRC}/qml/Muse/UiComponents/PageTabButton.qml
        ${UI_COMPONENTS_SRC}/qml/Muse/UiComponents/PopupPanel.qml
        ${UI_COMPONENTS_SRC}/qml/Muse/UiComponents/ProgressBar.qml
        ${UI_COMPONENTS_SRC}/qml/Muse/UiComponents/ProgressButton.qml
        ${UI_COMPONENTS_SRC}/qml/Muse/UiComponents/RadioButtonGroup.qml
        ${UI_COMPONENTS_SRC}/qml/Muse/UiComponents/RoundedRadioButton.qml
        ${UI_COMPONENTS_SRC}/qml/Muse/UiComponents/RoundedRectangle.qml
        ${UI_COMPONENTS_SRC}/qml/Muse/UiComponents/SearchField.qml
        ${UI_COMPONENTS_SRC}/qml/Muse/UiComponents/SelectMultipleDirectoriesDialog.qml
        ${UI_COMPONENTS_SRC}/qml/Muse/UiComponents/SeparatorLine.qml
        ${UI_COMPONENTS_SRC}/qml/Muse/UiComponents/StyledBusyIndicator.qml
        ${UI_COMPONENTS_SRC}/qml/Muse/UiComponents/StyledDialogView.qml
        ${UI_COMPONENTS_SRC}/qml/Muse/UiComponents/StyledDropShadow.qml
        ${UI_COMPONENTS_SRC}/qml/Muse/UiComponents/StyledDropdown.qml
        ${UI_COMPONENTS_SRC}/qml/Muse/UiComponents/StyledFlickable.qml
        ${UI_COMPONENTS_SRC}/qml/Muse/UiComponents/StyledGridView.qml
        ${UI_COMPONENTS_SRC}/qml/Muse/UiComponents/StyledGroupBox.qml
        ${UI_COMPONENTS_SRC}/qml/Muse/UiComponents/StyledIconLabel.qml
        ${UI_COMPONENTS_SRC}/qml/Muse/UiComponents/StyledListView.qml
        ${UI_COMPONENTS_SRC}/qml/Muse/UiComponents/StyledMenuLoader.qml
        ${UI_COMPONENTS_SRC}/qml/Muse/UiComponents/StyledPopupView.qml
        ${UI_COMPONENTS_SRC}/qml/Muse/UiComponents/StyledScrollBar.qml
        ${UI_COMPONENTS_SRC}/qml/Muse/UiComponents/StyledSlider.qml
        ${UI_COMPONENTS_SRC}/qml/Muse/UiComponents/StyledTabBar.qml
        ${UI_COMPONENTS_SRC}/qml/Muse/UiComponents/StyledTabButton.qml
        ${UI_COMPONENTS_SRC}/qml/Muse/UiComponents/StyledTextLabel.qml
        ${UI_COMPONENTS_SRC}/qml/Muse/UiComponents/StyledToolTip.qml
        ${UI_COMPONENTS_SRC}/qml/Muse/UiComponents/TextInputField.qml
        ${UI_COMPONENTS_SRC}/qml/Muse/UiComponents/TimeInputField.qml
        ${UI_COMPONENTS_SRC}/qml/Muse/UiComponents/ToggleButton.qml
        ${UI_COMPONENTS_SRC}/qml/Muse/UiComponents/ValueAdjustControl.qml
        ${UI_COMPONENTS_SRC}/qml/Muse/UiComponents/ValueList.qml
        ${UI_COMPONENTS_SRC}/qml/Muse/UiComponents/VisibilityBox.qml
        ${UI_COMPONENTS_SRC}/qml/Muse/UiComponents/internal/ArrowScrollButton.qml
        ${UI_COMPONENTS_SRC}/qml/Muse/UiComponents/internal/DirectoriesTopPanel.qml
        ${UI_COMPONENTS_SRC}/qml/Muse/UiComponents/internal/DirectoriesView.qml
        ${UI_COMPONENTS_SRC}/qml/Muse/UiComponents/internal/DropdownItem.qml
        ${UI_COMPONENTS_SRC}/qml/Muse/UiComponents/internal/GridViewDelegate.qml
        ${UI_COMPONENTS_SRC}/qml/Muse/UiComponents/internal/GridViewSection.qml
        ${UI_COMPONENTS_SRC}/qml/Muse/UiComponents/internal/MenuMetrics.qml
        ${UI_COMPONENTS_SRC}/qml/Muse/UiComponents/internal/PopupContent.qml
        ${UI_COMPONENTS_SRC}/qml/Muse/UiComponents/internal/StyledDropdownLoader.qml
        ${UI_COMPONENTS_SRC}/qml/Muse/UiComponents/internal/StyledDropdownView.qml
        ${UI_COMPONENTS_SRC}/qml/Muse/UiComponents/internal/StyledMenu.qml
        ${UI_COMPONENTS_SRC}/qml/Muse/UiComponents/internal/StyledMenuItem.qml
        ${UI_COMPONENTS_SRC}/qml/Muse/UiComponents/internal/ValueListHeaderItem.qml
        ${UI_COMPONENTS_SRC}/qml/Muse/UiComponents/internal/ValueListItem.qml
        ${UI_COMPONENTS_SRC}/qml/Muse/UiComponents/qmldir
        ${UI_COMPONENTS_SRC}/qml/Muse/UiComponents/treeview/BasicTableView.qml
        ${UI_COMPONENTS_SRC}/qml/Muse/UiComponents/treeview/BasicTableViewStyle.qml
        ${UI_COMPONENTS_SRC}/qml/Muse/UiComponents/treeview/ScrollBar.qml
        ${UI_COMPONENTS_SRC}/qml/Muse/UiComponents/treeview/ScrollView.qml
        ${UI_COMPONENTS_SRC}/qml/Muse/UiComponents/treeview/ScrollViewHelper.qml
        ${UI_COMPONENTS_SRC}/qml/Muse/UiComponents/treeview/ScrollViewStyle.qml
        ${UI_COMPONENTS_SRC}/qml/Muse/UiComponents/treeview/Style.qml
        ${UI_COMPONENTS_SRC}/qml/Muse/UiComponents/treeview/TableViewColumn.qml
        ${UI_COMPONENTS_SRC}/qml/Muse/UiComponents/treeview/TableViewItemDelegateLoader.qml
        ${UI_COMPONENTS_SRC}/qml/Muse/UiComponents/treeview/TreeView.qml
        ${UI_COMPONENTS_SRC}/qml/Muse/UiComponents/treeview/TreeViewItemDelegateLoader.qml
        ${UI_COMPONENTS_SRC}/qml/Muse/UiComponents/treeview/TreeViewStyle.qml
        ${UI_COMPONENTS_SRC}/qml/Muse/UiComponents/treeview/images/header.png
        ${UI_COMPONENTS_SRC}/qml/Muse/UiComponents/StyledToolBarView.qml
        ${UI_COMPONENTS_SRC}/qml/Muse/UiComponents/StyledToolBarItem.qml
        ${UI_COMPONENTS_SRC}/qml/Muse/UiComponents/TextInputArea.qml
        ${UI_COMPONENTS_SRC}/qml/Muse/UiComponents/StyledViewScrollAndZoomArea.qml
        ${UI_COMPONENTS_SRC}/qml/Muse/UiComponents/internal/ViewScrollBar.qml
        ${UI_COMPONENTS_SRC}/qml/Muse/UiComponents/RealInputField.qml
        ${UI_COMPONENTS_SRC}/qml/Muse/GraphicalEffects/qmldir
        ${UI_COMPONENTS_SRC}/qml/Muse/GraphicalEffects/EffectDropShadow.qml
        ${UI_COMPONENTS_SRC}/qml/Muse/GraphicalEffects/EffectOpacityMask.qml
        ${UI_COMPONENTS_SRC}/qml/Muse/GraphicalEffects/EffectRectangularGlow.qml
        ${UI_COMPONENTS_SRC}/qml/Muse/GraphicalEffects/EffectFastBlur.qml
        ${UI_COMPONENTS_SRC}/qml/Muse/GraphicalEffects/EffectColorOverlay.qml
    RESOURCES
        ${UI_COMPONENTS_SRC}/qml/Muse/UiComponents/Utils.js
)

qt_add_qml_module(${CMAKE_PROJECT_NAME}
    URI "${CMAKE_PROJECT_NAME}"
    VERSION 1.0
    NO_PLUGIN
    QML_FILES
        src/appshell/qml/Main.qml
        src/appshell/qml/WindowContents.qml
        src/appshell/qml/BaseCanvas.qml
        src/appshell/qml/Docks/PropertiesBar.qml
        src/appshell/qml/Docks/TimelineBar.qml
        src/appshell/qml/Docks/GeneralBar.qml
        src/appshell/qml/Docks/CentralWidget.qml
        src/appshell/qml/Topbar/Topbar.qml
        src/appshell/qml/Menu/AppWindow.qml
        src/appshell/qml/Menu/AppTitlebar.qml
        src/appshell/qml/Menu/AppMenubar.qml
        src/appshell/qml/Menu/AppButtonBackground.qml
        src/appshell/qml/Menu/AppSystemButtons.qml
        src/appshell/qml/Topbar/PlaybackWidget.qml
        src/appshell/qml/Topbar/QuickAccessBar.qml
        src/appshell/qml/Topbar/SwitchPageWidget.qml
        src/appshell/qml/Pages/EditPage.qml
        src/appshell/qml/Pages/RenderPage.qml
        src/appshell/qml/Pages/WelcomePage.qml
)

qt_add_translations(${CMAKE_PROJECT_NAME}
    TS_FILE_BASE ${CMAKE_PROJECT_NAME}
    TS_FILE_DIR ${CMAKE_SOURCE_DIR}/i18n/
)

################################################################################

# Qt libraries
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Svg
    Qt6::Qml
    Qt6::Quick
    Qt6::QuickControls2
)

# Include targets (UiComponents, ...)
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE UiComponents)

################################################################################

target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE src/)

################################################################################

#if(APPLE)
#    set(CMAKE_XCODE_ATTRIBUTE_CODE_SIGNING_REQUIRED "NO")
#    set(CMAKE_XCODE_ATTRIBUTE_CODE_SIGN_IDENTITY "")
#    set(CMAKE_XCODE_ATTRIBUTE_DEVELOPMENT_TEAM "")
#    set(CMAKE_XCODE_ATTRIBUTE_PROVISIONING_PROFILE "")
#endif()

## macOS
if(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    #set(CMAKE_OSX_ARCHITECTURES "x86_64;arm64")
    set(CMAKE_OSX_DEPLOYMENT_TARGET "11.0")

    set(app_icon_macos "${CMAKE_SOURCE_DIR}/assets/macos/${CMAKE_PROJECT_NAME}.icns")
    set_source_files_properties(${app_icon_macos} PROPERTIES MACOSX_PACKAGE_LOCATION "Resources")

    set_target_properties(${CMAKE_PROJECT_NAME} PROPERTIES
        MACOSX_BUNDLE ON
        MACOSX_BUNDLE_INFO_PLIST "${CMAKE_SOURCE_DIR}/assets/macos/Info.plist"
        # New Xcode attributes (???)
        XCODE_ATTRIBUTE_PRODUCT_BUNDLE_IDENTIFIER           "com.kaixoo12.advanced-effects"
        XCODE_ATTRIBUTE_PRODUCT_NAME                        ${CMAKE_PROJECT_NAME}
        XCODE_ATTRIBUTE_CURRENT_PROJECT_VERSION             ${CMAKE_PROJECT_VERSION}
        XCODE_ATTRIBUTE_MARKETING_VERSION                   ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
        XCODE_ATTRIBUTE_CODE_SIGN_ENTITLEMENTS             "${CMAKE_SOURCE_DIR}/assets/macos/${CMAKE_PROJECT_NAME}.entitlements"
    )
endif()

## iOS
if(CMAKE_SYSTEM_NAME STREQUAL "iOS")
    #set(app_icon_ios "${CMAKE_SOURCE_DIR}/assets/ios/Assets.xcassets")
    #set_source_files_properties(${app_icon_ios} PROPERTIES MACOSX_PACKAGE_LOCATION "Resources")

    set_target_properties(${CMAKE_PROJECT_NAME} PROPERTIES
        MACOSX_BUNDLE ON
        MACOSX_BUNDLE_INFO_PLIST "${CMAKE_SOURCE_DIR}/assets/ios/Info.plist"
        # Qt
        #QT_IOS_LAUNCH_SCREEN "${CMAKE_SOURCE_DIR}/assets/ios/LaunchScreen.storyboard"
        # New Xcode attributes (???)
        XCODE_ATTRIBUTE_PRODUCT_BUNDLE_IDENTIFIER           "com.kaixoo12.advanced-effects"
        XCODE_ATTRIBUTE_PRODUCT_NAME                        ${CMAKE_PROJECT_NAME}
        XCODE_ATTRIBUTE_CURRENT_PROJECT_VERSION             ${CMAKE_PROJECT_VERSION}
        XCODE_ATTRIBUTE_MARKETING_VERSION                   ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
        XCODE_ATTRIBUTE_IPHONEOS_DEPLOYMENT_TARGET          "14.0"
        XCODE_ATTRIBUTE_TARGETED_DEVICE_FAMILY              "1,2"   # iPhone,iPad
        XCODE_ATTRIBUTE_ASSETCATALOG_COMPILER_APPICON_NAME  "AppIcon"
        XCODE_ATTRIBUTE_GCC_GENERATE_DEBUGGING_SYMBOLS      "YES"
    )
endif()

## Windows
if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    set_target_properties(${CMAKE_PROJECT_NAME} PROPERTIES
        WIN32_EXECUTABLE ON
    )
endif()

## Release build? Set "no debug" macros
if(CMAKE_BUILD_TYPE STREQUAL Release)
    target_compile_definitions(${CMAKE_PROJECT_NAME} PRIVATE
        NDEBUG
        QT_NO_DEBUG
        QT_NO_DEBUG_OUTPUT
    )
endif()

################################################################################

# Output?
set_target_properties(${CMAKE_PROJECT_NAME} PROPERTIES
    #ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/lib"
    #LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/lib"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin"
)

# Output?
install(TARGETS ${CMAKE_PROJECT_NAME}
    BUNDLE DESTINATION "${CMAKE_SOURCE_DIR}/bin"
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

# Output?
# FIXME(kaixoo): Failing ???
#qt_generate_deploy_qml_app_script(
#    TARGET ${CMAKE_PROJECT_NAME}
#    OUTPUT_SCRIPT deploy_script
#    MACOS_BUNDLE_POST_BUILD
#    NO_UNSUPPORTED_PLATFORM_ERROR
#    DEPLOY_USER_QML_MODULES_ON_UNSUPPORTED_PLATFORM
#)
#install(SCRIPT ${deploy_script})

################################################################################
