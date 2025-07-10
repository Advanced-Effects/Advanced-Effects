declare_module(ae_project_file)
set(MODULE_ALIAS ae::project_file)

set(MODULE_ROOT ${CMAKE_CURRENT_LIST_DIR})

set(MODULE_SRC
    ProjectFile.h
    objects/node.h
    objects/node2d.h
    objects/keys/key.h
    objects/keys/range.h
    interfaces/SvgTrait.h
)

setup_module()
