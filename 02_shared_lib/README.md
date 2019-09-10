# A Hello World Sample Code in C

A little bit more enhanced hello world in C with following features:
* Simple Makefile with macro
* Create a .so shared library
* Create a hello binary which make use with foo.so shared library
* Makefile with quiet or verbose (V=1) option

Just use "make" to compile the program.  To run the "hello" program, make sure you put the current directory to LD_LIBRARY_PATH in order for the loader to find the foo.so.


Example usage:
``` sh

$ make V=1
-> Compiling foo.o
gcc -fPIC -c -o foo.o src/foo.c -Iinclude
-> Compiling libfoo.so
gcc -shared -o libfoo.so foo.o
-> Compiling hello
gcc -o hello src/hello.c -L. -lfoo -Iinclude
$ export LD_LIBRARY_PATH=$PWD
$ ldd hello 
	linux-vdso.so.1 =>  (0x00007fd48d821000)
	libfoo.so => /home/gideon/Development/hello/libfoo.so (0x00007fd48d3fc000)
	libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6 (0x00007fd48d032000)
	/lib64/ld-linux-x86-64.so.2 (0x00007fd48d5fe000)
$ ./hello 
Hello! This is a shared library test!

Hello, I'm a shared library

```
