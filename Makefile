#FIXME: Wait for update
## Main Makefile to compile sub directories

all: hello_01 hello_02_shared_lib

hello_01: hello_01/hello
	cd hello_01 ; make

hello_02_shared_lib:
	cd hello_02_shared_lib ; make

clean:
	rm -f *.o *~
	cd hello_01 ; make clean
	cd hello_02_shared_lib ; make clean
