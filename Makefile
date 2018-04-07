CPP=g++
CPPFLAGS=-Wall -fexceptions -g -fPIC
.PHONY: all
all: mat
mat: header
	@echo "Building example"
	$(CPP) -Wall -I include examples/mat.cpp -o mat
header:
	@echo "Checking Header"
	$(CPP) -fsyntax-only include/mat.h
