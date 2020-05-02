cmake_minimum_required(VERSION 3.5)

################## For CLANG FORMAT ##################

# Getting all the project files
file(GLOB_RECURSE
    ALL_CXX_SOURCE_FILES
    *.[chi]pp *.[chi]xx *.cc *.hh *.h *.ii *.[CHI]
    )

find_program(CLANG_FORMAT "clang_format")
if (CLANG_FORMAT)
    add_custom_target(
        clang-format
        COMMMAND /usr/bin/clang-format
        -i
        -style=../.clang-format
        ${ALL_CXX_SOURCE_FILES}
    )
endif()

find_program(CLANG_TIDY "clang_tidy")
if(CLANG_TIDY)
    add_custom_target(
        clang-tidy
        COMMAND /usr/bin/clang-tidy
        ${ALL_CXX_SOURCE_FILES}
        -config=''
        --
        -std=c++17
        ${INCLUDE_DIRECTORIES}
    )
endif()

# Reference can be found here, https://www.labri.fr/perso/fleury/posts/programming/using-clang-tidy-and-clang-format.html
