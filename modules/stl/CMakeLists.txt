add_library(StlModule stlModule.cxx)


#
# -------------------- C O N T A I N E R S -----------------------------
#
set(CONTAINERS_DIR ${CMAKE_SOURCE_DIR}/modules/stl/containers)
#
add_executable(array ${CONTAINERS_DIR}/array.cpp)
add_executable(vector ${CONTAINERS_DIR}/vector.cpp stlModule)
add_executable(set ${CONTAINERS_DIR}/set.cpp stlModule)
add_executable(list ${CONTAINERS_DIR}/list.cpp stlModule)
add_executable(stack ${CONTAINERS_DIR}/stack.cpp stlModule)
add_executable(queue ${CONTAINERS_DIR}/queue.cpp stlModule)
add_executable(deque ${CONTAINERS_DIR}/deque.cpp stlModule)
add_executable(prioryQueue ${CONTAINERS_DIR}/priorityQueue.cpp stlModule)


#
# -------------------- A L G O R I T H M S -----------------------------
#
#
set(ALGORITHMS_DIR ${CMAKE_SOURCE_DIR}/modules/stl/algorithms)
# #
add_executable(vectorAlgorithms ${ALGORITHMS_DIR}/vectorAlgorithms.cpp stlModule)
add_executable(listAlgorithms ${ALGORITHMS_DIR}/listAlgorithms.cpp stlModule)
add_executable(common ${ALGORITHMS_DIR}/common.cpp stlModule)




# state that anybody linking to us needs to include the current source dir
# to find MathFunctions.h, while we don't.
target_include_directories(StlModule
          INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
          )

# ---------------------- Installing Begin ----------------------
# specify install rules
# we want to install the library and header file and for the application 
# we want to install the executable and configured header.
install(TARGETS StlModule DESTINATION lib)
install(FILES StlModule.h DESTINATION include)

# ---------------------- Installing End ----------------------