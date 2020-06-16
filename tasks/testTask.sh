rm -rf build
mkdir build
cd build
rm ../testBuild.log
touch ../testBuild.log
cmake .. &>> ../testBuild.log
make &>> ../testBuild.log
./dashboard
cd ..
cp testBuild.log ../logs/testBuild.log