cmake_minimum_required(VERSION 3.12)
project(DataStructures)

# 设置编译器为g++
set(CMAKE_C_COMPILER "gcc")
set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_CXX_STANDARD 17)

# Add your source files here
set(
    SOURCES
    src/main.cpp
    src/disjointset.cpp
    src/graph.cpp
)

# 设置调试模式编译选项
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")

# 设置生成类型为调试
set(CMAKE_BUILD_TYPE Debug)

# Add your header files here
include_directories(include)

# Add any additional libraries or dependencies here
set(LIBRARIES
    # Example: pthread
)

# # 设置输出目录为Cmakelists所在的目录下的bin目录
# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# Add the executable target
add_executable(${PROJECT_NAME} ${SOURCES})

# Link any libraries or dependencies
target_link_libraries(${PROJECT_NAME} ${LIBRARIES})
