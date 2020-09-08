# File: Makefile

# Define compile command
CC=gcc

# Define include path
INC=inc


# Build Test.exe
Test : main.c src/*.c
	$(CC) -I$(INC) main.c src/*.c -o Test

clean:
	rm Test
