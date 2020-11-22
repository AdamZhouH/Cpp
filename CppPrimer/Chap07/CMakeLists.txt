cmake_minimum_required (VERSION 3.0)
# 增加C++11支持
# add_compile_options (-std=c++11)
# 或者使用如下的方式也可以，直接在CXX_FLAGS变量中加上C11支持
set (CMAKE_CXX_FLAGS -std=c++11)

project (fig07_2x)
message (STATUS "PROJECT_SOURCE_DIR" ${PROJECT_SOURCE_DIR})
message (STATUS "PROJECT_BINARY_DIR" ${PROJECT_BINARY_DIR})

include_directories (${PROJECT_SOURCE_DIR}/Class)
add_subdirectory (${PROJECT_SOURCE_DIR}/Class)
set (LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)
set (EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

#[[
set (CMAKE_CXX_FLAGS
        "${CMAKE_CXX_FLAGS}
        -lpthread")

message (STATUS "CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS}")
#]]
add_executable (Test fig07_2x.cpp)
target_link_libraries (Test Class)


