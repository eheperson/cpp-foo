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


# Configure the header file to passs the version number to the source code
configure_file(cppFooConfig.h.in cppFooConfig.h)

# add the executable
add_executable(${PROJECT_NAME} main.cpp)

# make the 'xxx' library optional
# this option will be displayed in the cmake-gui and ccmake with a default value of ON
option(BUILD_STL "Build cpp stl module tutorial files" OFF)
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


# add the binary tree to the search path for include files
# so that we will find exampleLib.h
# (paths to search for include files)
target_include_directories(${PROJECT_NAME} PUBLIC "${PROJECT_BINARY_DIR}")

#--------------------------------------------------------------------
#-------------- SDL2 Submodules Settings
add_executable(sdlTest src/sdlTest.cpp)
#
#--------------------------------------------------------------------
add_subdirectory (src)
#
target_link_libraries(sdlTest PUBLIC sdlTestLib )
#
#--------------------------------------------------------------------
#-------------- Particle Simulator 
add_executable(simulatorEHE ${LAB_DIR}/particleSimulator/main.cpp)
add_executable(colorAnimator ${LAB_DIR}/particleSimulator/colorAnimator.cpp)
add_executable(particleExample ${LAB_DIR}/particleSimulator/particleExample.cpp)
add_executable(particleExample2 ${LAB_DIR}/particleSimulator/particleExample2.cpp)
add_executable(particleMotionBasic ${LAB_DIR}/particleSimulator/particleMotionBasic.cpp)
add_executable(singlePixel ${LAB_DIR}/particleSimulator/singlePixel.cpp)
#
add_subdirectory (${LAB_DIR}/particleSimulator)
#
target_link_libraries(simulatorEHE PUBLIC screen)
target_link_libraries(simulatorEHE PUBLIC particle)
target_link_libraries(simulatorEHE PUBLIC swarm)
#
target_link_libraries(colorAnimator PUBLIC screen)
target_link_libraries(colorAnimator PUBLIC particle)
target_link_libraries(colorAnimator PUBLIC swarm)
#
target_link_libraries(particleExample PUBLIC screen)
target_link_libraries(particleExample PUBLIC particle)
target_link_libraries(particleExample PUBLIC swarm)
#
target_link_libraries(particleExample2 PUBLIC screen)
target_link_libraries(particleExample2 PUBLIC particle)
target_link_libraries(particleExample2 PUBLIC swarm)
#
target_link_libraries(particleMotionBasic PUBLIC screen)
target_link_libraries(particleMotionBasic PUBLIC particle)
target_link_libraries(particleMotionBasic PUBLIC swarm)
#
target_link_libraries(singlePixel PUBLIC screen)
target_link_libraries(singlePixel PUBLIC particle)
target_link_libraries(singlePixel PUBLIC swarm)

#--------------------------------------------------------------------
#-------------- DOWNLOAD ALL THE SUBMODULES
# first open terminal and type : 
#   git submodule add https://github.com/libsdl-org/SDL.git libs/sdl
#   git submodule add -f https://github.com/libsdl-org/SDL.git libs/sdl
# second add changes to staged area (we have to stage it)
#  
find_package(Git QUIET)
if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
# Update submodules as needed
    option(GIT_SUBMODULE "Check submodules during build" ON)
    if(GIT_SUBMODULE)
        message(STATUS "Submodule update")
        execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
                        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                        RESULT_VARIABLE GIT_SUBMOD_RESULT)
        if(NOT GIT_SUBMOD_RESULT EQUAL "0")
            message(FATAL_ERROR "git submodule update --init failed with ${GIT_SUBMOD_RESULT}, please checkout submodules")
        endif()
    endif()
endif()
#
#--------------------------------------------------------------------
#-------------- CHECK ALL THE SUBMODULES
if(NOT EXISTS "${PROJECT_SOURCE_DIR}/external/sdl2/CMakeLists.txt")
    message(FATAL_ERROR "The sdl2 submodules was not downloaded! GIT_SUBMODULE was turned off or failed. Please update submodules and try again.")
endif()
#
#--------------------------------------------------------------------
add_subdirectory(${PROJECT_SOURCE_DIR}/external/sdl2)
