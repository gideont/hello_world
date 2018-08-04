# A Hello World Sample Code in C

A little bit more enhanced hello world in C with following features:
* Simple Makefile with macro
* Create a .so shared library
* Create a hello binary which make use with foo.so shared library
* Makefile with quiet or verbose (V=1) option

Just use "make" to compile the program.  To run the "hello" program, make sure you put the current directory to LD_LIBRARY_PATH in order for the loader to find the foo.so.


Example usage:
```bash
gideon@dgx-1:~/hello(master)$ make V=1
-> Compiling foo.o
gcc -c -fPIC -o foo.o foo.c
-> Compiling libfoo.so
gcc -shared -o libfoo.so foo.o
-> Compiling hello.o
gcc -c -fPIC -o hello.o hello.c
-> Compiling hello
gcc -o hello hello.o -L. -lfoo 
gideon@dgx-1:~/hello(master)$ export LD_LIBRARY_PATH=$PWD
gideon@dgx-1:~/hello(master)$ ldd hello
	linux-vdso.so.1 =>  (0x00007fff9a18a000)
	libfoo.so => /home/gideon/hello/libfoo.so (0x00007f345e9ca000)
	libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6 (0x00007f345e600000)
	/lib64/ld-linux-x86-64.so.2 (0x00007f345ebcc000)
gideon@dgx-1:~/hello(master)$ ./hello 
Hello! This is a shared library test!

Hello, I'm a shared library
gideon@dgx-1:~/hello(master)$ 
```
