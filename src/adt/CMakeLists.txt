add_executable(array_adt_c array_adt_c.cpp)
target_include_directories(array_adt_c PRIVATE ${CMAKE_BINARY_DIR})

add_executable(linked_list_c linked_list_c.cpp)
target_include_directories(linked_list_c PRIVATE ${CMAKE_BINARY_DIR})

add_executable(matrix_c matrix_c.cpp)
target_include_directories(matrix_c PRIVATE ${CMAKE_BINARY_DIR})

add_executable(matrix_cpp matrix_cpp.cpp)
target_include_directories(matrix_cpp PRIVATE ${CMAKE_BINARY_DIR})