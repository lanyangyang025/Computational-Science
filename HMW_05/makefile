### Begin MACROS
#Define compiler
CC=g++
#Define linker
LD=g++
#Compilation flags
CFLAGS=
#Link flags
LDFLAGS=
#Define addition librariry (like -lm)
LIBS=-llapack -lblas -lgfortran
#Define include path (where header file could be)
INCLUDE=./
#Define sources files to compile
SOURCES=main.cc my_matrix.cc
#Define generated object files from SOURCES
OBJECTS=$(SOURCES:.cc=.o)
#Define name executable
EXEC=a.exe
### End MACROS

### Begin targets
build: $(EXEC) $(SOURCES)

$(EXEC) : $(OBJECTS)
	$(LD) $(LDFLAGS) $(OBJECTS) $(LIBS) -o $@
%.o: %.c
	$(CC) $(CFLAGS) -I$(INCLUDE) $< -o $@

#Define additional action
clean :
	rm -rf $(OBJECTS)

all : clean build
### End targets
