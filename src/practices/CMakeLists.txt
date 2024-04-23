
add_executable(pointer_to_struct pointer_to_struct.cpp)
target_include_directories(pointer_to_struct PRIVATE ${CMAKE_BINARY_DIR})

add_executable(struct_as_parameter struct_as_parameter.cpp)
target_include_directories(struct_as_parameter PRIVATE ${CMAKE_BINARY_DIR})

add_executable(array_as_parameter array_as_parameter.cpp)
target_include_directories(array_as_parameter PRIVATE ${CMAKE_BINARY_DIR})

add_executable(monolithic_program monolithic_program.cpp)
target_include_directories(monolithic_program PRIVATE ${CMAKE_BINARY_DIR})

add_executable(return_types return_types.cpp)
target_include_directories(return_types PRIVATE ${CMAKE_BINARY_DIR})

add_executable(parameter_passing_methods parameter_passing_methods.cpp)
target_include_directories(parameter_passing_methods PRIVATE ${CMAKE_BINARY_DIR})

add_executable(static_vs_dynamic_arrays static_vs_dynamic_arrays.cpp)
target_include_directories(static_vs_dynamic_arrays PRIVATE ${CMAKE_BINARY_DIR})

add_executable(2d_arrays 2d_arrays.cpp)
target_include_directories(2d_arrays PRIVATE ${CMAKE_BINARY_DIR})

add_executable(recursion_practices recursion_practices.cpp)
target_include_directories(recursion_practices PRIVATE ${CMAKE_BINARY_DIR})

add_executable(increasing_array_size increasing_array_size.cpp)
target_include_directories(increasing_array_size PRIVATE ${CMAKE_BINARY_DIR})
