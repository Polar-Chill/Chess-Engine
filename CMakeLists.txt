cmake_minimum_required(VERSION 3.10)
project(ChessEngine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -O0 -Wall -Wextra")

find_package(Qt5 COMPONENTS Widgets REQUIRED)

# Collect all .cpp files in the src directory and the engine subdirectory
file(GLOB_RECURSE SRC_FILES src/*.cpp src/engine/*.cpp)

# Collect all .h files in the src directory and the engine subdirectory (for reference)
file(GLOB_RECURSE HEADER_FILES src/*.h src/engine/*.h)

# Add the executable target with all source files
add_executable(${PROJECT_NAME} ${SRC_FILES})

# Include the src and engine directories for header files
target_include_directories(${PROJECT_NAME} PRIVATE src src/engine)

# Link against the required Qt libraries
target_link_libraries(${PROJECT_NAME} Qt5::Widgets)

# Output binary location and build type
message(STATUS "Executable will be generated at: ${CMAKE_BINARY_DIR}/${PROJECT_NAME}")
