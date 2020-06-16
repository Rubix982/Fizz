cmake_minimum_required(VERSION 3.1.0)

project(dashboard)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

find_package(Qt5 COMPONENTS Widgets REQUIRED)

set(HEADERS
    classes/helpFuncs.hpp
    classes/systemInfoClass.hpp
    dashboard/include/networks.hpp
)

set(SOURCES
    testing.cpp
    classes/hardwareInfo.cpp
    classes/kernelInfo.cpp
    dashboard/src/systemInfo.cpp
)

add_executable(dashboard ${SOURCES} ${HEADERS})

target_link_libraries(dashboard Qt5::Widgets Qt5::Core)