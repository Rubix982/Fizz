function cppcheck_build {
    echo "" &>> ./logs/build.log
    echo "---------" &>> ./logs/build.log
    echo "[CPPCHECK] Running cppcheck ... " &>> ./logs/build.log
    echo "---------" &>> ./logs/build.log
    cppcheck -i build -i googletest -i cmake . &>> ./logs/build.log
}

function build() {
    echo "---------" &>> ./logs/build.log
    echo "[BUILD] Building for target ... " &>> ./logs/build.log
    echo "---------" &>> ./logs/build.log

    uic interface/mainwindow.ui -o include/ui_mainwindow.h

    cmake --target all --no-warn-unused-cli -DCMAKE_EXPORT_COMPILE_COMMANDS:BOOL=TRUE \
    -DCMAKE_BUILD_TYPE:STRING=Debug -DCMAKE_C_COMPILER:FILEPATH=/usr/bin/gcc \
    -DCMAKE_CXX_COMPILER:FILEPATH=/usr/bin/g++ \
    -H/home/saif/Desktop/Folders/University/OS/Project \
    -B/home/saif/Desktop/Folders/University/OS/Project/build -G Ninja &>> ./logs/build.log
}

function run_build() {

    # run the executable
    echo "" &>> ./logs/build.log
    echo "---------" &>> ./logs/build.log
    echo "[RUN + VALGRIND] Running executable ... " &>> ./logs/build.log
    echo "---------" &>> ./logs/build.log
    valgrind --tool=memcheck --leak-check=yes build/Fizz &>> ./logs/build.log
}

function test_build() {
    # run the tests
    echo "" &>> ./logs/build.log
    echo "---------" &>> ./logs/build.log
    echo "[TEST] Running tests ... " &>> ./logs/build.log
    echo "---------" &>> ./logs/build.log
    cmake --build /home/saif/Desktop/Folders/University/OS/Project/build --config Debug --target all -- -j 6 &>> ./logs/build.log
}

function clear_log() {
    # clear the log file
    rm ./logs/build.log
    touch ./logs/build.log
}

function generate_docs() {
    echo "" &>> ./logs/build.log
    echo "---------" &>> ./logs/build.log
    echo "[DOC] Generating documentation ... " &>> ./logs/build.log
    echo "---------" &>> ./logs/build.log
    doxygen docs/Doxyfile &>> ./logs/build.log
}

# MAIN functionality starts here

number_of_arguments=$#
if [ $number_of_arguments -gt 1 ]
then
    printf "Wrong method of input - ${number_of_arguments} provided ... \n"
    printf "Write ./build.sh to build, test, and run ... \n"
    printf "Else, use only 1 argument from the following\n"
    printf "[all, build, test, run, clear_log]\n"
    exit
elif [ "$#" == 0 -o "$#" = "all" ]
then

    # performs ALL the instructions
    # printf "In all\n"

    clear_log # Clear the file
    build # build the project
    test_build # Run the tests
    generate_docs # generate the relevant documentation
    cppcheck_build # run cpp check over the files
    run_build # Run the executable with valgrind

elif [ "$1" = "clean" ]
then

    # printf "In clean\n"
    echo "[BUILD] Removing build directory ... "
    rm -r build

elif [ "$1" = "build" ]
then

    # printf "In build\n"
    build # build the project

elif [ "$1" = "test" ]
then

    # printf "In test\n"
    test_build # Run the tests

elif [ "$1" = "run" ]
then

    # printf "In run\n"
    run_build  # run the build

elif [ "$1" = "clear" ]
then

    # printf "In clear\n"
    clear_log # Clear the log file

fi