#
#
# We will put the library into a subdirectory called 'fileOperations'
# We have to add thatlne to the 'CMakeLists.txt' in the 'fileOperations' directory
# add_library(fileOperations main.cpp fileOperations.h)
add_executable(fileOperations main.cpp fileOperations.h)



# Adding a Library to use the modern CMake approach of usage requirements. 
# first state that anybody linking to exampleLib needs to include the current source directory, 
# while exampleLib itself doesn't. 
# So this can become an INTERFACE usage requirement.
#   Remember INTERFACE means things that consumers require but the producer doesn't
# Now that we've specified usage requirements for MathFunctions 
target_include_directories(fileOperations
          INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
          )


# Installing --------------------------------------------------------------------------------
# Installing rules For Library :
# The install rules are fairly simple: 
#   for exampleLib we want to install the library and header file
#   for the application we want to install the executable and configured header.
install(TARGETS fileOperations DESTINATION modules)
install(FILES fileOperations.h DESTINATION include)
