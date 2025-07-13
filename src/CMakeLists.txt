
###########################################
# Include subdirectories (libraries)
###########################################

# Library, should be first to work
# Contains core libraries required for the program to work,
# and the UI components library
add_subdirectory(library)

# Services, in between library and appshell
add_subdirectory(services)

# Appshell (Application GUI)
add_subdirectory(appshell)

# Finally, squash everything together in application/
add_subdirectory(application)
