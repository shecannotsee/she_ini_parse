########################################################################################################################
cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(PROJECT_NAME "example")
set(CMAKE_CXX_FLAGS "-g")# 断点无效处理方案
project(${PROJECT_NAME})

set(CMAKE_PREFIX_PATH "/home/shecannotsee/desktop/all_code/she_ini_parse/cmake-build-debug/she_ini_parse")
find_package(she_ini_parse)

if (${she_ini_parse_FOUND})
    # include
    include_directories(${she_ini_parse_INCLUDE_DIR})
    # lib
    link_directories(${she_ini_parse_LIBRARIES})
else ()
    message(ERROR "can not find she_ini_parse")
endif ()

# include
include_directories()
# lib
link_directories()

file(GLOB_RECURSE SRC "${CMAKE_SOURCE_DIR}/main.cpp")
add_executable(${PROJECT_NAME} ${SRC})

# 链接库
target_link_libraries(${PROJECT_NAME} "-pthread" ${she_ini_parse_LINK_TARGET})

########################################################################################################################

