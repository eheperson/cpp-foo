#
add_executable(atomicc ./atomicc.cpp)
add_executable(nullptr ./nullptr.cpp)
# if (LIBCXX_HAS_ATOMIC_LIB)
#     target_link_libraries(nullptr PRIVATE atomic)
# endif()


#  if(ATOMIC)
#         set(LIBATOMIC ${ATOMIC})
#         message(STATUS "Found libatomic: ${LIBATOMIC}")