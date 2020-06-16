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
cmake_minimum_required(VERSION 2.8.11)

if(POLICY CMP0023)
  cmake_policy(SET CMP0023 NEW)
endif()

if (POLICY CMP0028)
    cmake_policy(SET CMP0028 NEW)
endif()

# Manages version variables
if (POLICY CMP0048)
    cmake_policy(SET CMP0048 NEW)
endif()

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
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS YES)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
add_definitions(-DQT_DEPRECATED_WARNINGS)

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

# Adding features(build cache + faster linkers) and reasonable defaults(Debug build by default)
include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/cxxbasics/CXXBasics.cmake")

# Use Qt5 resources
# qt5_add_resources(QRC
#     resources/qrcFiles/qml.qrc
# )

set(RESOURCES
    resources/qrcFiles/qml.qrc
)

# Use QT5 ui
set(UI
    ${INTERFACE_DIR}/mainwindow.ui
)

# Adding sources
set(SOURCES
        ${SRC_DIR}/${ENTRY_POINT}

        ${SRC_DIR}/backend/mainwindow.cpp

        ${SRC_DIR}/dashboard/networks.cpp
        ${SRC_DIR}/dashboard/usage.cpp
        ${SRC_DIR}/dashboard/systemInfo.cpp

        resources/qrcFiles/main.qml
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

# Find QT5, QML
find_package(Qt5 COMPONENTS QuickWidgets Gui Qml Quick Core Network Widgets LinguistTools OpenGL QuickCompiler REQUIRED)

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
add_library(${PROJECT_NAME} ${UI} ${RESOURCES} ${SOURCES} ${HEADERS} ${TS_FILES_ALL} ${QRC} )
else()
add_executable(${PROJECT_NAME} ${UI} ${RESOURCES} ${SOURCES} ${HEADERS} ${TS_FILES_ALL} ${QRC})
endif()

add_subdirectory(test)

# For qt5 / QML
qt5_use_modules(${PROJECT_NAME} QuickWidgets Quick Core Network Widgets LinguistTools OpenGL QuickCompiler Gui Qml)

set_target_properties(${PROJECT_NAME} PROPERTIES
   RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/$<CONFIG>/plugins/${QmlPluginName}/)

## QT related additions
target_link_libraries(${PROJECT_NAME} ${Qt5Widgets_LIBRARIES} Qt5::Widgets Qt5::Quick Qt5::Qml Qt5::Core Qt5::Network Qt5::Gui Qt5::QuickWidgets  Qt5::OpenGL)
qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})

# message("Copying required Qt libraries and binaries to output directory ... ")
# add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_PREFIX_PATH}\\bin $<TARGET_FILE_DIR:${PROJECT_NAME}>)

# add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_PREFIX_PATH}\\plugins $<TARGET_FILE_DIR:${PROJECT_NAME}>)

# add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_PREFIX_PATH}\\qml $<TARGET_FILE_DIR:${PROJECT_NAME}>)

############

# @references
# See https://stackoverflow.com/questions/46862737/cmake-qt-uic-failed