![Fizz logo](./img/Logo/logo_transparent.png)

# Fizz

A UI and dashboard for system processes, memory, CPU usage, and common Operating System statistics.

Designed using 
- Cmake 
- QMake
- QT

---

## The Folder Structure

- ***docs***: Should contain documentation - empty for now
- ***img***: Should contain any required or needed images for the project
- ***include***: Includes the header / .ui files
- ***interface***: Should contain symlinks to the ui files
- ***misc***: Any misc logs or files
- ***resources***: Should contain qrc files
- ***src***: Main .cpp / .c files
- ***tasks***: Modular approach to just targeting each part of TODO, and integrating into main project after everything of that feature is complete
- ***test***: I'll write tests here if needed
- ***TODO***: Info about tasks remaining, done, and current.
- ***TSFiles***: Contains files for translation with QtLinguistic

--- 

## Root File Structure

- ***.clang-format***: Contains default styling method for keeping code clean
- ***.clang-tidy***: Contains basic configurations for code cleanliness
- ***.gitignore***: For ignoring build folder, and IDE folder
- ***CMakeLists.txt***: Root CMakeFile to build with
- ***CMakeLists.txt.usr***: Basic user settings for CMake
- ***requirements.txt***: Should contain the needed packages to build and run Fizz

## Build Configurations

- Needed packages have been ( or will be ) added to requirements to txt.
- Built, designed, and debugged on OS, `Linux archlinux 5.5.3-arch1-1 #1 SMP PREEMPT Tue, 11 Feb 2020 15:35:41 +0000 x86_64 GNU/Linux.`
- CMake version used `3.16.4`
- QMake version `3.1`
- Using Qt version `5.14.1` in `/usr/lib`

## How To build

- In the root directory run
```
$ chmod +x ./build.sh
$ ./build.sh
```

## References

- [GNU Coreutils - Core GNU utilities](https://www.gnu.org/software/coreutils/manual/coreutils.html#toc-Summarizing-files-1)