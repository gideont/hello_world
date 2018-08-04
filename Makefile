CC=gcc

# make V=1 for verbose mode, quiet by default
ifeq ("$(V)","1")
Q :=
vecho = @echo
else
	Q := @
	vecho = @true
	endif

DEPS = foo.h hello.c
OBJ = foo.o 

all: libfoo.so hello

%.o: %.c $(DEPS)
	$(vecho) "-> Compiling $@"
	$(Q)$(CC) -c -fPIC -o $@ $<

libfoo.so: foo.o
	$(vecho) "-> Compiling $@"
	$(Q)$(CC) -shared -o $@ $^

hello: hello.o
	$(vecho) "-> Compiling $@"
	$(Q)$(CC) -o $@ $^ -L. -lfoo 

.PHONY: clean

clean:
	rm -f *.o hello libfoo.so
