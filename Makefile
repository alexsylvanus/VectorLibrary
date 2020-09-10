# File: Makefile

# Define compile command
CC=gcc

# Define include path
INC=inc

OBJ_LOC=obj
# Get C files
SRC=$(wildcard src/*.c)
OBJ1=$(patsubst src/%.c,%.o,$(SRC))
OBJ=$(patsubst %,obj/%,$(OBJ1))

# Build Test.exe
Test : $(OBJ_LOC)/main.o $(OBJ) # main.o adate.o astring.o avector.o vectorTest.o 
	$(CC) $(OBJ_LOC)/*.o -o Test -I$(INC)

$(OBJ_LOC)/%.o : src/%.c
	$(CC) -c $^ -o $@ -I$(INC)

$(OBJ_LOC)/main.o : main.c
	$(CC) -c main.c -o $@ -I$(INC)

.Phony : clean

clean:
	rm Test $(OBJ_LOC)/*.o
