declare_module(app_projectscene)
set(MODULE_ALIAS app::projectscene)

set(MODULE_QRC projectscene.qrc)
set(MODULE_QML_IMPORT ${CMAKE_CURRENT_LIST_DIR}/qml)

set(MODULE_SRC
        projectscenemodule.h
        projectscenemodule.cpp
        iprojectfilescontroller.h
        view/toolbarmodel.h
        view/toolbarmodel.cpp
        view/canvas/applicationcanvas.h
        view/canvas/applicationcanvas.cpp
        view/timeline/timelinecontext.h
        view/timeline/keysview.h
        view/timeline/keysview.cpp
        internal/projectfilescontroller.h
        internal/projectfilescontroller.cpp
        internal/projectactionscontroller.h
        internal/projectactionscontroller.cpp
        internal/projectuiactions.h
        internal/projectuiactions.cpp
        internal/toolbar/toolactioncontroller.h
        internal/toolbar/toolactioncontroller.cpp
        internal/toolbar/toolbaractions.h
        internal/toolbar/toolbaractions.cpp
        internal/toolbar/toolidentifier.h
    )

set(MODULE_LINK
    muse::uicomponents
    muse::ui)

set(MODULE_LINK_PUBLIC
        app::context
        ${SKIA_LIBRARIES})

setup_module()

set_source_files_properties(${MODULE_SRC}
                            PROPERTIES
                            SKIP_UNITY_BUILD_INCLUSION ON
                            SKIP_PRECOMPILE_HEADERS ON)
