CC=gcc
CFLAGS=-Iinclude -Wl,-rpath=.
SRC_DIR=src

# make V=1 for verbose mode, quiet by default
V=0
ifeq ("$(V)","1")
Q :=
vecho = @echo
else
	Q := @
	vecho = @true
	endif

DEPS = $(SRC_DIR)/foo.c

all: libfoo.so hello

foo.o: $(DEPS)
	$(vecho) "-> Compiling $@"
	$(Q)$(CC) -fPIC -c -o $@ $< $(CFLAGS)

libfoo.so: foo.o
	$(vecho) "-> Compiling $@"
	$(Q)$(CC) -shared -o $@ $^

hello: $(SRC_DIR)/hello.c
	$(vecho) "-> Compiling $@"
	$(Q)$(CC) -o $@ $^ -L. -lfoo $(CFLAGS)

.PHONY: clean

clean:
	rm -f *.o hello libfoo.so
