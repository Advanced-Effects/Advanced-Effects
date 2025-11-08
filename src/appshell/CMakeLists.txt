declare_module(app_appshell)
set(MODULE_ALIAS app::appshell)

set(MODULE_QRC appshell.qrc)
set(MODULE_QML_IMPORT ${CMAKE_CURRENT_LIST_DIR}/qml)

set(MODULE_SRC
    appshellmodule.h
    appshellmodule.cpp
    view/toolbarmodel.h
    view/toolbarmodel.cpp
    iappshellconfiguration.h
    view/appmenumodel.h
    view/appmenumodel.cpp
    view/navigableappmenumodel.h
    view/navigableappmenumodel.cpp
    view/mainwindowtitleprovider.h
    view/mainwindowtitleprovider.cpp
    view/internal/iappmenumodelhook.h
    view/preferences/preferencesmodel.h
    view/preferences/preferencesmodel.cpp
    view/preferences/preferencepageitem.h
    view/preferences/preferencepageitem.cpp
    view/canvas/applicationcanvas.h
    view/canvas/applicationcanvas.cpp
    view/preferences/preferencesmodel.h
    view/preferences/preferencesmodel.cpp
    view/preferences/preferencepageitem.h
    view/preferences/preferencepageitem.cpp
    view/framelesswindow/framelesswindowmodel.h
    view/framelesswindow/framelesswindowmodel.cpp
    internal/platformdetails.h
    internal/platformdetails.cpp
    internal/appshellactions.h
    internal/appshellactions.cpp
    internal/toolbar/toolactioncontroller.h
    internal/toolbar/toolactioncontroller.cpp
    internal/toolbar/toolbaractions.h
    internal/toolbar/toolbaractions.cpp
    internal/toolbar/toolidentifier.h
    internal/appshellactionscontroller.h
    internal/appshellactionscontroller.cpp
    internal/framelesswindowcontroller.h
    internal/framelesswindowcontroller.cpp
    )

set(MODULE_LINK
    muse::uicomponents
    muse::ui
    muse::dockwindow
    )

set(MODULE_LINK_PUBLIC app::context)

set(MODULE_INCLUDE
        ${PROJECT_SOURCE_DIR}/thirdparty/potrace/src
        ${PROJECT_SOURCE_DIR}/thirdparty/QtAppSetup/src
        ${PROJECT_SOURCE_DIR}/src/glax_core)

# we use private/qkeymapper_p.h to fix https://github.com/musescore/MuseScore/issues/10181
set(MODULE_INCLUDE_PRIVATE ${Qt6Gui_PRIVATE_INCLUDE_DIRS} )

setup_module()
