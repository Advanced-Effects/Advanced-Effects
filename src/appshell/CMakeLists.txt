declare_module(ae_appshell)
set(MODULE_ALIAS ae::appshell)

set(MODULE_ROOT ${CMAKE_CURRENT_LIST_DIR})

set(MODULE_QRC appshell.qrc)
set(MODULE_QML_IMPORT ${CMAKE_CURRENT_LIST_DIR}/qml)

set(MODULE_SRC
    ${CMAKE_CURRENT_LIST_DIR}/appshellmodule.h
    ${CMAKE_CURRENT_LIST_DIR}/appshellmodule.cpp
    ${CMAKE_CURRENT_LIST_DIR}/view/appmenumodel.h
    ${CMAKE_CURRENT_LIST_DIR}/view/appmenumodel.cpp
    ${CMAKE_CURRENT_LIST_DIR}/internal/mainwindowtitleprovider.cpp
    ${CMAKE_CURRENT_LIST_DIR}/internal/mainwindowtitleprovider.h)

setup_module()
