# Change version of the cmake accorting of your   <REQUIRED>
cmake_minimum_required(VERSION 3.21.3 FATAL_ERROR)

# Do not forget update the compiler path <REQUIRED>
# set(CMAKE_C_COMPILER "/usr/bin/gcc")
# set(CMAKE_CXX_COMPILER "/usr/bin/g++")
# add_definitions(-std=c++11)

# Specify C++ standards
# C++ standards declerations must be above the call to add_executable
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)


# SOME SETTINGS
set(CMAKE_BUILD_TYPE Debug)

# Set some required variables 
set(MODULES_DIR ${CMAKE_SOURCE_DIR}/modules)
set(LAB_DIR ${CMAKE_SOURCE_DIR}/lab)

# set the project name with version
# ${PROJECT_NAME}
project(cppFoo VERSION 1.0.0)

option(BUILD_SHARED_LIBS "Build using shared libraries" OFF)

# configure a header file to pass some of the CMake settings
# to the source code
configure_file(Config.h.in Config.h)

# make the 'xxx' library optional
# this option will be displayed in the cmake-gui and ccmake with a default value of ON
option(BUILD_STL "Build cpp stl module tutorial files" ON)
option(BUILD_LOOPS "Build cpp loops tutorial files" ON)
option(BUILD_FILEOPERATIONS "Build cpp file operations module tutorial files" OFF)
option(BUILD_CONST "Build cpp const keyword module tutorial files" OFF)
option(BUILD_STRUCT "Build cpp structures module tutorial files" OFF)
option(BUILD_TEMPLATES "Build cpp templates module tutorial files" OFF)

if(BUILD_STL)
    add_subdirectory(${MODULES_DIR}/stl)
endif()
if(BUILD_FILEOPERATIONS)
    add_subdirectory(${MODULES_DIR}/fileOperations)
endif()
if(BUILD_CONST)
    add_subdirectory(${MODULES_DIR}/const)
endif()
if(BUILD_STRUCT)
    add_subdirectory(${MODULES_DIR}/struct)
endif()
if(BUILD_TEMPLATES)
    add_subdirectory(${MODULES_DIR}/templates)
endif()
if(BUILD_LOOPS)
    add_subdirectory(${MODULES_DIR}/loops)
endif()


# add the executable
add_executable(${PROJECT_NAME} main.cxx)

target_link_libraries(${CMAKE_PROJECT_NAME} PUBLIC ${EXTRA_LIBS})

# add the binary tree to the search path for include files
# so that we will find EnivicivokkiConfig.h
target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )

# ---------------------- Installing Begin ----------------------
# add the install targets
install(TARGETS ${CMAKE_PROJECT_NAME} DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/Config.h"
  DESTINATION include
  )
# ---------------------- Installing End ------------------------