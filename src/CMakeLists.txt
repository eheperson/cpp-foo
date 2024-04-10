add_executable(${PROJECT_NAME} main.cpp)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_BINARY_DIR})

add_executable(arrays arrays.cpp)
target_include_directories(arrays PRIVATE ${CMAKE_BINARY_DIR})

add_executable(structures structures.cpp)
target_include_directories(structures PRIVATE ${CMAKE_BINARY_DIR})