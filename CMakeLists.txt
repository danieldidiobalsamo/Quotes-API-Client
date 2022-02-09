cmake_minimum_required(VERSION 3.10)

project(Quotes-API-Client)

# C++ standard and compilation flags
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-pedantic -Wall -Wextra -Werror -Wconversion -Wsign-conversion -Wold-style-cast -g")

# packages
find_package(Qt5 COMPONENTS Quick Network REQUIRED)

# CMake tools
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# sources

set(SRC
    src/main.cpp
    src/Quote.cpp
    src/QuoteListModel.cpp
    src/QuotesAPI.cpp
    src/BackEnd.cpp
    src/RequestWorker.cpp

    include/Quote.hpp
    include/QuoteListModel.hpp
    include/QuotesAPI.hpp
    include/BackEnd.hpp
    include/RequestWorker.hpp
    
    qml/main.qrc)

include_directories(include)

# executable
add_executable(Quotes-API-Client ${SRC})
target_link_libraries(Quotes-API-Client PUBLIC Qt5::Quick Qt5::Network)