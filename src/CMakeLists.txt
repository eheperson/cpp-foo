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


add_executable(prac_pointer_to_struct practices/pointer_to_struct.cpp)
target_include_directories(prac_pointer_to_struct PRIVATE ${CMAKE_BINARY_DIR})