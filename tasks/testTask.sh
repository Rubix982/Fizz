rm -rf build
mkdir build
cd build
cmake .. &>> ../testBuild.log
make &>> ../testBuild.log
./dashboard
cd ..
cp testBuild.log ../logs/testBuild.log