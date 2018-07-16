ifeq ($(OS),Windows_NT)
	LIB=libmat.dll
	PATHSEP=\
	EXEC=mat.exe
	CP=copy
else
	UNAME_S:= $(shell uname -s)
	ifeq ($(UNAME_S),Linux)
		LIB=libmat.so
		PATHSEP=/
		EXEC=mat
		CP=cp
	endif
	ifeq ($(UNAME_S),Darwin)
		LIB=libmat.dylib
		PATHSEP=/
		EXEC=mat
		CP=cp
	endif
endif
ifneq ($(CXX),)
	CXX=g++
	CPPFLAGS=-Wall -fexceptions -Iinclude -Linclude -lmat
	LIBFLAGS=-shared -fPIC -Wall -fexceptions
else
	ifeq ($(CXX),g++)
		CPPFLAGS=-Wall -fexceptions -Iinclude -Linclude -lmat
		LIBFLAGS=-shared -fPIC -Wall -fexceptions
	endif
endif
all: $(LIB)
$(EXEC): $(LIB)
	@echo "Building $(EXEC)"
	$(CXX) examples$(PATHSEP)mat.cpp  $(CPPFLAGS) -o examples$(PATHSEP)$(EXEC)
header:
	@echo "Checking Header"
	$(CXX) -fsyntax-only -Wcpp include$(PATHSEP)mat.h
$(LIB): header
	@echo "Building $(LIB)"
	$(CXX) include$(PATHSEP)lib.cpp $(LIBFLAGS) -o include$(PATHSEP)$(LIB)
clean: 
	@echo "Cleaning"
	rm -f include$(PATHSEP)libmat.so examples$(PATHSEP)$(EXEC) $(LIB)
test: clean $(EXEC)
	@echo "Running $(EXEC)"
	@$(CP) include$(PATHSEP)$(LIB) $(LIB)
	LD_LIBRARY_PATH=. examples$(PATHSEP)${EXEC}
debug: clean
	@echo "Preparing for debugging"
	@echo "Checking Header"
	$(CXX) -fsyntax-only -Wcpp include$(PATHSEP)mat.h
	@echo "Building $(LIB)"
	$(CXX) include$(PATHSEP)lib.cpp $(LIBFLAGS) -g -o include$(PATHSEP)$(LIB)
	$(CXX) examples$(PATHSEP)mat.cpp  $(CPPFLAGS) -g -o examples$(PATHSEP)$(EXEC)
	@echo "Debugging $(EXEC)"
	@$(CP) include$(PATHSEP)$(LIB) $(LIB)
	LD_LIBRARY_PATH=. gdb examples$(PATHSEP)${EXEC}
	@make clean
