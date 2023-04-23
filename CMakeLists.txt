cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(kanaExam VERSION 1.0)

# Set the C++ standard to use
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the source files
set(SOURCES
    BuildMap.cpp
    common.cpp
    kanaExam.cpp
    kanas.cpp
    Score.cpp
)

# Add the header files
set(HEADERS
    BuildMap.h
    common.h
    kanas.h
    Score.h
)

# Add the executable
add_executable(kana ${SOURCES} ${HEADERS})

# Set any additional include directories
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# Set any additional libraries to link against
target_link_libraries(kana pthread)
