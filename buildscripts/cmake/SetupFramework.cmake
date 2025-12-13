include(FetchContent)

FetchContent_Declare(Framework
        GIT_REPOSITORY https://github.com/Advanced-Effects/framework.git
        GIT_TAG main)

FetchContent_MakeAvailable(Framework)
# Make "muse_create_module" macros available
include(DeclareModuleSetup)
