# File: Makefile

# Define compile command
CC=gcc

# Define include path
INC=inc

# Define the library path
LDIR=lib

# Define object folders
ODIR_S=obj_static
ODIR_D=obj_dynamic

# Check if Windows or Linux
ifeq ($(OS), Windows_NT)
	# Set library name
	LIB=libavector.dll
else
	LIB=libavector.so
endif

# Get C files
SRC=$(wildcard src/*.c)
OBJ=$(patsubst src/%.c,%.o,$(SRC))
OBJ_S=$(patsubst %,$(ODIR_S)/%,$(OBJ))
OBJ_D=$(patsubst %,$(ODIR_D)/%,$(OBJ))

# Build Test.exe
Test : $(ODIR_S)/main.o $(OBJ_S) $(LDIR)/$(LIB) # main.o adate.o astring.o avector.o vectorTest.o 
	$(CC) -L$(LDIR) $(ODIR_S)/*.o -o Test -lavector -WL,-rpath,$(PWD)/$(LDIR)

lib : $(OBJ_D)
	$(CC) -shared -o $(LIB) $(ODIR_D)/*.o

$(LDIR)/$(LIB) : $(OBJ_D)
	if [ ! -d "$(LDIR)" ]; then mkdir $(LDIR); fi
	$(CC) -shared -o $(LDIR)/$(LIB) $(ODIR_D)/*.o

$(ODIR_D)/%.o : src/%.c
	if [ ! -d "$(ODIR_D)" ]; then mkdir $(ODIR_D); fi
	$(CC) -fPIC -c $^ -o $@ -I$(INC)

$(ODIR_S)/%.o : src/%.c
	$(CC) -c $^ -o $@ -I$(INC)

$(ODIR_S)/main.o : main.c
	$(CC) -c main.c -o $@ -I$(INC)

.Phony : clean

clean:
	rm Test $(ODIR_S)/*.o $(ODIR_D)/*.o $(LIB)
