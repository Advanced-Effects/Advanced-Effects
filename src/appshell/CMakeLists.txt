declare_module(app_appshell)
set(MODULE_ALIAS app::appshell)

set(MODULE_QRC appshell.qrc)
set(MODULE_QML_IMPORT ${CMAKE_CURRENT_LIST_DIR}/qml)

set(MODULE_SRC
    appshellmodule.h
    appshellmodule.cpp
    view/appmenumodel.h
    view/appmenumodel.cpp
    view/mainwindowtitleprovider.h
    view/mainwindowtitleprovider.cpp
    view/internal/iappmenumodelhook.h
    )

set(MODULE_LINK
    muse::uicomponents
    muse::ui
    muse::dockwindow
    )

setup_module()

