cmake_minimum_required(VERSION 3.15)
project(Fizz C CXX)

# For QT
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# The CXX standard
set(CMAKE_CXX_STANDARD 20)

# For SRC dir
set(SRC_DIR src)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_compile_options(-Wall -Wextra -O2)

add_executable(Fizz ${SRC_DIR}/main.cpp)

target_link_libraries(Fizz Qt5::Widgets)