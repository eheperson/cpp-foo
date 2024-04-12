add_executable(${PROJECT_NAME} main.cpp)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_BINARY_DIR})

add_executable(arrays arrays.cpp)
target_include_directories(arrays PRIVATE ${CMAKE_BINARY_DIR})

add_executable(structures structures.cpp)
target_include_directories(structures PRIVATE ${CMAKE_BINARY_DIR})

add_executable(pointers pointers.cpp)
target_include_directories(pointers PRIVATE ${CMAKE_BINARY_DIR})

add_executable(references references.cpp)
target_include_directories(references PRIVATE ${CMAKE_BINARY_DIR})

add_executable(functions functions.cpp)
target_include_directories(functions PRIVATE ${CMAKE_BINARY_DIR})

add_executable(oop-basics oop-basics.cpp)
target_include_directories(oop-basics PRIVATE ${CMAKE_BINARY_DIR})

add_executable(template_class template_class.cpp)
target_include_directories(template_class PRIVATE ${CMAKE_BINARY_DIR})

add_executable(template_function template_function.cpp)
target_include_directories(template_function PRIVATE ${CMAKE_BINARY_DIR})

add_executable(prac_pointer_to_struct practices/pointer_to_struct.cpp)
target_include_directories(prac_pointer_to_struct PRIVATE ${CMAKE_BINARY_DIR})

add_executable(prac_array_as_parameter practices/array_as_parameter.cpp)
target_include_directories(prac_array_as_parameter PRIVATE ${CMAKE_BINARY_DIR})
