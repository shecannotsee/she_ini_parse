
########################################################################################################################
# Import lib                                                                                                           #
########################################################################################################################

set(gtest "${CMAKE_SOURCE_DIR}/third_party/googletest")

# include
include_directories(${gtest}/include)

# lib
link_directories(${gtest}/lib)

# Internal project
include_directories(${CMAKE_SOURCE_DIR}/src)
include_directories(${CMAKE_SOURCE_DIR}/test)
include_directories(${CMAKE_SOURCE_DIR}/exec)


