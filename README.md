# Fizz

A UI and dashboard for system processes, memory, CPU usage, and common Operating System statistics.

Designed using 
- Cmake 
- QMake
- QT

---

## The File Structure

- ***img***: Should contain any required or needed images for the project
- ***include***: Includes the header / .ui files
- ***interface***: Should contain symlinks to the ui files
- ***misc***: Any misc logs or files
- ***resources***: Should contain qrc files
- ***src***: Main .cpp / .c files 

## Root file structure

- ***.clang-format***: Contains default styling method for keeping code clean
- ***.clang-tidy***: Contains basic configurations for code cleanliness
- ***.gitignore***: For ignoring build folder, and IDE folder
- ***CMakeLists.txt***: Root CMakeFile to build with
- ***CMakeLists.txt.usr***: Basic user settings for CMake 