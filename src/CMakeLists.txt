# Library, should be first to work
# Contains core libraries required for the program to work,
# and the UI components library
add_subdirectory(library)

# Appshell (Application GUI)
add_subdirectory(appshell)

# App (main executable)
# Links all libraries together
add_subdirectory(app)
