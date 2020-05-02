# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check http://doc.qt.io/qt-5/deployment-android.html for more information.
# They need to be set before the find_package(Qt5 ...) call.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

# @param CMake version -- REQUIRED
cmake_minimum_required(VERSION 3.5)

# @param Should be the project name
set(PROJECT_NAME Fizz)

project(${PROJECT_NAME} LANGUAGES C CXX)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

# For QT
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# For testing related configurations
enable_testing()

add_subdirectory(googletest)
# End testing related configurations

# For SRC dir and CMake Macros
set(SRC_DIR src)
set(INCLUDE_DIR include)
set(INTERFACE_DIR interface)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOUIC_SEARCH_PATHS ${INTERFACE_DIR})
# set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -L . -lpthread")

# For TS { translation }  file s
set(TS_FILE_DIR ts_files)
set(TS_FILES testing_with_cmake_en_001.ts)

# Project configurations
set(ENTRY_POINT main.cpp)

## Local header files
include_directories(${INCLUDE_DIR})

# Use Qt5 resources
set(RESOURCES
    ./resources/qrcFiles/style.qrc
)

# Use QT5 ui
set(UI 
    ${INTERFACE_DIR}/mainwindow.ui
)

# Adding sources
set(SOURCES
        ${SRC_DIR}/${ENTRY_POINT}
        ${SRC_DIR}/mainwindow.cpp
        
        ${SRC_DIR}/dashboard/networks.cpp
        ${SRC_DIR}/dashboard/usage.cpp
        ${SRC_DIR}/dashboard/systemInfo.cpp
)

# Adding the headers
set(HEADERS
        ${INCLUDE_DIR}/mainwindow.h
        ${INCLUDE_DIR}/ui_mainwindow.h
        ${INCLUDE_DIR}/moc_predefs.h 
        
        ${INCLUDE_DIR}/dashboard/networks.h
        ${INCLUDE_DIR}/dashboard/usage.h
        ${INCLUDE_DIR}/dashboard/systemInfo.h
)

# Adding the TS files
set(TS_FILES_ALL
        ${TS_FILE_DIR}/${TS_FILES} 
)

################## For CLANG FORMAT ##################

# Getting all the project files

# include(cmake/clang-cxx-dev-tools.cmake)

# Additional targets to perform clang-format/clang-tidy
# Get all project files
file(GLOB_RECURSE
     ALL_CXX_SOURCE_FILES
     include/*.[chi]pp include/*.[chi]xx include/*.cc include/*.hh include/*.h include/*.ii include/*.[CHI]
     src/*.[chi]pp src/*.[chi]xx src/*.cc src/*.hh src/*.h src/*.ii src/*.[CHI]
     test/*.[chi]pp test/*.[chi]xx test/*.cc test/*.hh test/*.h test/*.ii test/*.[CHI]
     )

message(STATUS "All files found by GLOB_RECURSE:")

message(STATUS "           ${ALL_CXX_SOURCE_FILES}" )

# Adding clang-format target if executable is found
find_program(CLANG_FORMAT "clang-format")
if(CLANG_FORMAT)
    message(STATUS "[CMAKE] Found clang-format")
  add_custom_target(
    clang-format
    COMMAND /usr/bin/clang-format
    -i
    -style="./clang-format"
    ${ALL_CXX_SOURCE_FILES}
    )
endif()

# Adding clang-tidy target if executable is found
find_program(CLANG_TIDY "clang-tidy")
if(CLANG_TIDY)
message(STATUS "[CMAKE] Found from clang-tidy")
add_custom_target(
    clang-tidy
    COMMAND /usr/bin/clang-tidy
    ${ALL_CXX_SOURCE_FILES}
    -config=''
    --
    -std=c++11
    ${INCLUDE_DIRECTORIES}
    )
endif()

# Reference can be found here, https://www.labri.fr/perso/fleury/posts/programming/using-clang-tidy-and-clang-format.html

################## END For CLANG FORMAT ##################

# Find QT5
find_package(Qt5 COMPONENTS Core Widgets LinguistTools OpenGL REQUIRED)
# Add Qt5 definitions and includes to build libraries.
# Widgets add Widgets Core and Gui
add_definitions(${Qt5Widgets_DEFINITIONS})
include_directories(${Qt5Widgets_INCLUDES})

add_definitions(${Qt5OpenGL_DEFINITIONS})
include_directories(${Qt5OpenGL_INCLUDES})

# Add some compiler options
add_compile_options(-Wall -Wextra -O2 -fPIC)

message(STATUS "UI detected: ${UI}")
message(STATUS "RESOURCES detected: ${RESOURCES}")
message(STATUS "SOURCES detected: ${SOURCES}")
message(STATUS "HEADERS detected: ${HEADERS}")
message(STATUS "TS_FILES detected: ${TS_FILES_ALL}")

if(ANDROID)
    add_library(${PROJECT_NAME} ${UI} ${RESOURCES} ${SOURCES} ${HEADERS}  ${TS_FILES_ALL} )
else()
    add_executable(${PROJECT_NAME} ${UI} ${RESOURCES} ${SOURCES} ${HEADERS}  ${TS_FILES_ALL} )
endif()

add_subdirectory(test)

## QT related additions
target_link_libraries(${PROJECT_NAME} PRIVATE ${Qt5Widgets_LIBRARIES} Qt5::Widgets)
qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})

############

# @references
# See https://stackoverflow.com/questions/46862737/cmake-qt-uic-failed