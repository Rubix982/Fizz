cmake_minimum_required(VERSION 3.8)

set(TEST_NAME ExampleTest)
set(SRC_DIR src)
set(INCLUDE_DIR include)

set(SOURCES
    ${SRC_DIR}/ExampleTest.cpp
)

set(HEADERS
    ${INCLUDE_DIR}/ExampleTest.hpp
)

add_executable(${TEST_NAME} ${SOURCES} ${HEADERS})
target_link_libraries(${TEST_NAME} PUBLIC
    gtest_main
    # Fizz
)

add_test(
    NAME ${TEST_NAME}
    COMMAND ${TEST_NAME}
)