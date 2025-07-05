declare_module(ae_appshell)
set(MODULE_ALIAS ae::appshell)

set(MODULE_ROOT ${CMAKE_CURRENT_LIST_DIR})

set(MODULE_QRC appshell.qrc)
set(MODULE_QML_IMPORT ${CMAKE_CURRENT_LIST_DIR}/qml)

set(MODULE_SRC
    internal/basecanvas.h
    internal/basecanvas.cpp)


set(MODULE_LINK
    ae::ui
    ae::uicomponents
    ae::dockwindow
)

setup_module()
