CPP=g++
CPPFLAGS=-Wall -fexceptions -g -fPIC
.PHONY: all
all: mat
mat:
	@echo "Building example"
	$(CPP) -Wall -I include examples/mat.cpp -o mat
