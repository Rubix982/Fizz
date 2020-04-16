if [ "$#" == 1 ]; then
    if [ "$1" = "clean" ]; then
        echo "[BUILD] Removing build directory ... "
        rm -r build
        exit
    # elif [ ! -d "build"]; then
    #     echo "[BUILD] build directory does not exist to clean it. Exiting ... " 
    #     exit
    else 
        echo "[BUILD] only argument \"clean\" is expected. Exiitng ... "
        exit
    fi
fi

# general output to show user
echo "[BUILD] Building, testing, and running ... " 

# empty the log file
echo "" > ./logs/build.log

# build for the files
echo "---------" > /dev/null 2>&1 >> ./logs/build.log
echo "Building for target" > /dev/null 2>&1 >> ./logs/build.log
echo "---------" > /dev/null 2>&1 >> ./logs/build.log
cmake --no-warn-unused-cli -DCMAKE_EXPORT_COMPILE_COMMANDS:BOOL=TRUE \
-DCMAKE_BUILD_TYPE:STRING=Debug -DCMAKE_C_COMPILER:FILEPATH=/usr/bin/gcc \
-DCMAKE_CXX_COMPILER:FILEPATH=/usr/bin/g++ \
-H/home/saif/Desktop/Folders/University/OS/Project \
-B/home/saif/Desktop/Folders/University/OS/Project/build -G Ninja > /dev/null 2>&1 >> ./logs/build.log

# run the tests
echo "---------" > /dev/null 2>&1 >> ./logs/build.log
echo "Running tests" > /dev/null 2>&1 >> ./logs/build.log
echo "---------" > /dev/null 2>&1 >> ./logs/build.log
cmake --build /home/saif/Desktop/Folders/University/OS/Project/build --config Debug --target all -- -j 6 > /dev/null 2>&1 >> ./logs/build.log

# run the executable
echo "---------" > /dev/null 2>&1 >> ./logs/build.log
echo "Running executable" > /dev/null 2>&1 >> ./logs/build.log
echo "---------" > /dev/null 2>&1 >> ./logs/build.log
build/Fizz > /dev/null 2>&1 >> ./logs/build.log