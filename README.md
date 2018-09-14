# Some Hello World Sample Code

This is a little collection of hello world in C:
* hello_01 is the most basic hello world in C, with a Makefile showing the build command.
* hello_02_shared_lib is a bit more enhanced hello world in C, with a more robust Makefile and creating/linking a .so shared library.
* hello_03_cmake is an example using cmake
* hello_99_deb is a demostration how to build a deb package.

The Makefile in project base directory serve as an example to build subdirectories projects.

The Recursive.mk serves as a recursive Makefile to build subdirectories projects. Use the file with command `make -f Recursive.mk`
