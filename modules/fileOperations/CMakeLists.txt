#
#
# We will put the library into a subdirectory called 'fileOperations'
# We have to add thatlne to the 'CMakeLists.txt' in the 'fileOperations' directory
# add_library(fileOperations main.cpp fileOperations.h)
add_executable(fileOperations main.cpp fileOperations.cpp)

