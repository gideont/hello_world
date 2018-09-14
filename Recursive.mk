# This is an example Makefile for recursive make of subdirectories

MODULES = hello_01 hello_02_shared_lib

all:
	for dir in $(MODULES); do \
	  (cd $$dir; ${MAKE} all); \
	done

## Alternative recursive make
#SUBDIRS = $(shell ls -d */)
#all:
#	for dir in $(SUBDIRS) ; do \
#        make -C  $$dir ; \
#    done
