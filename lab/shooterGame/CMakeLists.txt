
# #--------------------------------------------------------------------
# 
add_library(structs
            INTERFACE
            Specs/Strutcs.h
            )
#
target_include_directories(structs INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}") # include
#
target_include_directories(structs  # include
                           INTERFACE external/sdl2/include
                           INTERFACE external/sdl_image)
#
target_link_directories(structs  #linker
                        INTERFACE external/sdl2
                        INTERFACE external/sdl_image)
#
target_link_libraries(structs  #linker
                    #   INTERFACE SDL2main 
                      INTERFACE SDL2 
                    #   INTERFACE SDL2-static
                      INTERFACE SDL2_image)
#
# #--------------------------------------------------------------------
#
# #--------------------------------------------------------------------
# 
add_library(defs
            INTERFACE
            Specs/Defs.h)
#
target_include_directories(defs INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}") #include
#
target_include_directories(defs #include
                           INTERFACE external/sdl2/include
                           INTERFACE external/sdl_image)
#
target_link_directories(defs  #linker
                        INTERFACE external/sdl2
                        INTERFACE external/sdl_image)
#
target_link_libraries(defs 
                    #   INTERFACE SDL2main 
                      INTERFACE SDL2 
                    #   INTERFACE SDL2-static
                      INTERFACE SDL2_image)
#
# #--------------------------------------------------------------------
# 
# #--------------------------------------------------------------------
# 
add_library(common
            INTERFACE
            Specs/Common.h)
#
target_include_directories(common INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}") #include
#
target_include_directories(common #include
                           INTERFACE external/sdl2/include
                           INTERFACE external/sdl_image)
#
target_link_directories(common  #linker
                        INTERFACE external/sdl2
                        INTERFACE external/sdl_image)
#
target_link_libraries(common  #linker
                    #   INTERFACE SDL2main 
                      INTERFACE SDL2 
                    #   INTERFACE SDL2-static
                      INTERFACE SDL2_image)
#
# #--------------------------------------------------------------------
# 
# #--------------------------------------------------------------------
# 
add_library(draw
            Draw/Draw.h
            Draw/Draw.cpp)
#
target_include_directories(draw PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}") #include
#
target_include_directories(draw  #include
                           PUBLIC external/sdl2/include
                           PUBLIC external/sdl_image)
#
target_link_directories(draw  #linker
                        PUBLIC external/sdl2
                        PUBLIC external/sdl_image)
#
target_link_libraries(draw  #linker
                    #   PUBLIC SDL2main 
                      PUBLIC SDL2 
                    #   PUBLIC SDL2-static
                      PUBLIC SDL2_image)
#
# #--------------------------------------------------------------------
# 
# #--------------------------------------------------------------------
# 
add_library(init
            Init/Init.h
            Init/Init.cpp)
#
target_include_directories(init PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}") #include
#
target_include_directories(init  #include
                           PUBLIC external/sdl2/include
                           PUBLIC external/sdl_image)
#
target_link_directories(init #linker
                        PUBLIC external/sdl2
                        PUBLIC external/sdl_image)
#
target_link_libraries(init  #linker
                    #   PUBLIC SDL2main 
                      PUBLIC SDL2 
                    #   PUBLIC SDL2-static 
                      PUBLIC SDL2_image)
#
# #--------------------------------------------------------------------
# 
# #--------------------------------------------------------------------
# 
add_library(input
            Input/Input.h
            Input/Input.cpp)
#
target_include_directories(input PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}") #include
#
target_include_directories(input    #include
                           PUBLIC external/sdl2/include
                           PUBLIC external/sdl_image)
#
target_link_directories(input  #linker
                        PUBLIC external/sdl2
                        PUBLIC external/sdl_image)
#
target_link_libraries(input #linker
                    #   PUBLIC SDL2main 
                      PUBLIC SDL2 
                    #   PUBLIC SDL2-static
                      PUBLIC SDL2_image)
#
# #--------------------------------------------------------------------
# 
