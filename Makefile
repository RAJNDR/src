#Copyright Notice:
#The files within this zip file are copyrighted by Lazy Foo' Productions (2004-2014)
#and may not be redistributed without written permission.

#OBJS specifies which files to compile as part of the project
#OBJS = main.cpp
#dependencies
#DEPS = testWindow.hpp

#CC specifies which compiler we're using
CC = g++
SRC = src
ODIR = obj
IDIR = include

_DEPS = testWindow.hpp
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))
#INCLUDE_PATHS specifies the additional include paths we'll need
INCLUDE_PATHS = -Iinclude -IC:\mingw_dev_lib\include\SDL2

#LIBRARY_PATHS specifies the additional library paths we'll need
LIBRARY_PATHS = -LC:\mingw_dev_lib\lib

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
# -Wl,-subsystem,windows gets rid of the console window
COMPILER_FLAGS = -w -Wl,-subsystem,windows

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -lmingw32 -lSDL2main -lSDL2

_OBJ = testWindow.o main.o
OBJS = $(patsubst %,$(ODIR)/%,$(_OBJ))

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = main


$(ODIR)/%.o:  $(SRC)/%.cpp $(DEPS)
	$(CC) -g -c -o $@ $< $(INCLUDE_PATHS) $(COMPILER_FLAGS) $(LIBRARY_PATHS)

#This is the target that compiles our executable
all : $(OBJS)
	$(CC) -g -o $(OBJ_NAME) $(OBJS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(LINKER_FLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(IDIR)/*~ main.exe