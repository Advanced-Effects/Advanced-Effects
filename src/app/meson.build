app_link = [
        dep_qt,

        dep_muse_global,

        dep_muse_autobot,
        dep_muse_draw,
        dep_muse_actions,
        dep_muse_ui,
        dep_muse_uicomponents,
        dep_muse_dockwindow,
        dep_muse_shortcuts,
        dep_muse_workspace,
        dep_muse_accessibility,
        dep_muse_cloud,
        dep_muse_network,
        dep_muse_multiinstances,
        dep_muse_learn,
        dep_muse_languages,
        dep_muse_diagnostics,

        dep_qtappsetup,

        lib_app_glax_core,
        lib_app_context,
        lib_app_projectscene,
        lib_app_appshell
]

app_src = [
        'main.cpp',
        'commandlineparser.h',
        'commandlineparser.cpp',
        'application.h',
        'application.cpp'
]

app_include = [
        meson.project_binary_root(),
        meson.project_source_root() / 'src',

        muse_framework_path,
        muse_framework_path / 'framework',
        muse_framework_path / 'framework' / 'global'
]

app = executable(meson.project_name(), app_src,
        link_with: app_link,
        include_directories: app_include)
