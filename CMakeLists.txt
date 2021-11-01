cmake_minimum_required(VERSION 3.10)

project(Wikiquote-cpp-client)

# C++ standard and compilation flags
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-pedantic -Wall -Wextra -Werror -Wconversion -Wsign-conversion -Wold-style-cast -g")

# packages
find_package(Qt5 COMPONENTS Widgets Quick Core Network REQUIRED)
find_package(Qt5QuickCompiler)

# CMake tools
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# source files
set(SRC_FILES src/Quote.cpp)
set(QT_RELATED_SRC src/QuoteListModel.cpp src/NetworkManager.cpp src/BackEnd.cpp)

# MOC
qt5_wrap_cpp(MOC_FILES include/QuoteListModel.hpp include/NetworkManager.hpp include/BackEnd.hpp)
qtquick_compiler_add_resources(RESOURCES qml/main.qrc)

# headers
include_directories(include)

# executable
add_executable(Wikiquote-cpp-client src/main.cpp ${QT_RELATED_SRC} ${SRC_FILES} ${RESOURCES} ${MOC_FILES})
target_link_libraries(Wikiquote-cpp-client PUBLIC Qt5::Widgets Qt5::Quick Qt5::Core Qt5::Network)