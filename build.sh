function build() {
    echo "---------" > /dev/null 2>&1 >> ./logs/build.log
    echo "[BUILD] Building for target ... " > /dev/null 2>&1 >> ./logs/build.log
    echo "---------" > /dev/null 2>&1 >> ./logs/build.log
    cmake --no-warn-unused-cli -DCMAKE_EXPORT_COMPILE_COMMANDS:BOOL=TRUE \
    -DCMAKE_BUILD_TYPE:STRING=Debug -DCMAKE_C_COMPILER:FILEPATH=/usr/bin/gcc \
    -DCMAKE_CXX_COMPILER:FILEPATH=/usr/bin/g++ \
    -H/home/saif/Desktop/Folders/University/OS/Project \
    -B/home/saif/Desktop/Folders/University/OS/Project/build -G Ninja > /dev/null 2>&1 >> ./logs/build.log    
}

function run_build() {
    # run the executable
    echo "---------" > /dev/null 2>&1 >> ./logs/build.log
    echo "[RUN] Running executable ... " > /dev/null 2>&1 >> ./logs/build.log
    echo "---------" > /dev/null 2>&1 >> ./logs/build.log
    build/Fizz > /dev/null 2>&1 >> ./logs/build.log
}

function test_build() {
    # run the tests
    echo "---------" > /dev/null 2>&1 >> ./logs/build.log
    echo "[TEST] Running tests ... " > /dev/null 2>&1 >> ./logs/build.log
    echo "---------" > /dev/null 2>&1 >> ./logs/build.log
    cmake --build /home/saif/Desktop/Folders/University/OS/Project/build --config Debug --target all -- -j 6 > /dev/null 2>&1 >> ./logs/build.log
}

function clear_log() {
    # clear the log file
    rm ./logs/build.log
    touch ./logs/build.log
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
    run_build # Run the executable_

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