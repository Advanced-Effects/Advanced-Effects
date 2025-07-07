# Framework, should be first to work pch
# Contains core libraries required for the program to work,
# and the UI components library
add_subdirectory(library)

# Appshell (Application GUI)
add_subdirectory(appshell)

# App (main executable)
add_subdirectory(app)
