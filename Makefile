CXX=g++
CPPFLAGS=-Wall -fexceptions -Iinclude -Linclude -lmat
LIBFLAGS=-shared -fPIC -Wall -fexceptions
.PHONY: all
all: libmat.so
mat: libmat.so
	@echo "Building example"
	$(CXX) examples/mat.cpp  $(CPPFLAGS) -o examples/mat
header:
	@echo "Checking Header"
	$(CXX) -fsyntax-only -Wcpp include/mat.h
libmat.so: header
	@echo "Building Library"
	$(CXX) include/lib.cpp $(LIBFLAGS) -o include/libmat.so
clean: 
	@echo "Cleaning"
	rm -f include/libmat.so examples/mat libmat.so
test: clean mat
	@echo "Starting example executable"
	@ln -s include/libmat.so libmat.so
	LD_LIBRARY_PATH=. examples/mat
