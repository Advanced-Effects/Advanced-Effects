declare_module(app_appshell)
set(MODULE_ALIAS app::appshell)

set(MODULE_QRC appshell.qrc)
set(MODULE_QML_IMPORT ${CMAKE_CURRENT_LIST_DIR}/qml)

set(MODULE_SRC
    appshellmodule.h
    appshellmodule.cpp
    iappshellconfiguration.h
    view/toolselectionmodel.h
    view/toolselectionmodel.cpp
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
    internal/appshellactions.h
    internal/appshellactions.cpp
    internal/appshellactionscontroller.h
    internal/appshellactionscontroller.cpp
    )

set(MODULE_LINK
    muse::uicomponents
    muse::ui
    muse::dockwindow
    )

# we use private/qkeymapper_p.h to fix https://github.com/musescore/MuseScore/issues/10181
set(MODULE_INCLUDE_PRIVATE ${Qt6Gui_PRIVATE_INCLUDE_DIRS} )

setup_module()
