# File: Makefile

# Define include path
INC=inc

# Build Test.exe
Test : main.c src/*.c
	gcc -I$(INC) main.c src/*.c -o Test

clean:
	rm Test.exe
