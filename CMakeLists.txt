cmake_minimum_required(VERSION 3.10)

project(Wikiquote-cpp-client)

# C++ standard and compilation flags
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-pedantic -Wall -Wextra -Werror -Wconversion -Wsign-conversion -Wold-style-cast -g")

# C++ packages
find_package(Qt5 COMPONENTS Widgets Quick Core REQUIRED)
find_package(Qt5QuickCompiler)

# CMake tools
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# source files
qtquick_compiler_add_resources(RESOURCES qml/main.qrc)

#executable
add_executable(Wikiquote-cpp-client src/main.cpp ${RESOURCES})
target_link_libraries(Wikiquote-cpp-client PUBLIC Qt5::Widgets Qt5::Quick Qt5::Core)