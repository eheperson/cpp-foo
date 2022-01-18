# #--------------------------------------------------------------------
add_library(sdlTestLib
            sdlTestLib/sdlTestLib.h
            sdlTestLib/sdlTestLib.cpp)
#
target_include_directories(sdlTestLib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
#
target_include_directories(sdlTestLib PUBLIC external/sdl2/include)
target_link_directories(sdlTestLib PUBLIC external/sdl2)
target_link_libraries(sdlTestLib PUBLIC SDL2main SDL2 SDL2-static) # This code works on MAC OS (MAC_OS_CODE)
# and this code below works on WIN
# target_link_libraries(particle PUBLIC mingw32 SDL2main SDL2) # 'mingw32 SDL2main SDL2' order important  (WIN_CODE)
# TODO : check if MAC_OS_CODE will work on WIN_CODE
# #
# #--------------------------------------------------------------------
# example library linking for windows systems
# add_library(particle
#             Particle/Particle.h
#             Particle/Particle.cpp)
# #
# target_include_directories(particle PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
# #
# target_include_directories(particle PUBLIC libs/sdl/include)
# target_link_directories(particle PUBLIC libs/sdl)
# target_link_libraries(particle PUBLIC mingw32 SDL2main SDL2) # 'mingw32 SDL2main SDL2' order important
# #--------------------------------------------------------------------
