# File: Makefile

Test : main.c src/*.c
	gcc main.c src/*.c -o Test

clean:
	rm Test.exe
