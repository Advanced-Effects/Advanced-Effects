declare_module(app_projectscene)
set(MODULE_ALIAS app::projectscene)

set(MODULE_QRC projectscene.qrc)
set(MODULE_QML_IMPORT ${CMAKE_CURRENT_LIST_DIR}/qml)

set(MODULE_SRC
        projectscenemodule.h
        projectscenemodule.cpp
        internal/mocktreemodel.h
        internal/mocktreemodel.cpp
        view/timeline/timelinecontext.h
        view/timeline/keysview.h
        view/timeline/keysview.cpp
    )

set(MODULE_LINK
    muse::uicomponents
    muse::ui
    )

setup_module()
