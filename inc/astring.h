/*	File:			astring.h
	Location:		/GCC_Projects/VectorLib/inc/astring.h
	Time:			12:24:11 PM
	Date:			November 15, 2018
	Author:			alexs
	Description:	Function Definitions for astring library
*/

// Begin header file
#ifndef INC_ASTRING_H_
#define INC_ASTRING_H_

// Type Definitions
typedef struct STR String_t;
typedef String_t* string_t;

// Functions
// Vector-type Functions
void append(string_t s, char value); // Add a char to the end, equivalent to push
char pop(string_t s); // Get the last value and remove it from the string
void clear(string_t s); // Clear the string and free the memory allocated
void sPrint(string_t s); // Print the string struct to the console

// Initialization functions
void sClear(string_t s);
string_t sInit(const char* s); // Initialize string with constant character array
string_t sCopy(string_t s);
bool sEquals(string_t s, const char* literal);

// Get functions
char getC(string_t s, int index); // Get a character at a specific index
char* getStr(string_t s);
size_t getLength(string_t s);

// Manipulate functions
string_t sAdd(string_t s1, string_t s2);
string_t sAdd_c(string_t s1, string_t s2);

// Conversion functions
string_t strI(int val); // Int to string_t conversion
string_t strF(float val); // Float to string_t conversion
string_t strD(double val); // Double to string_t conversion

#endif /* INC_ASTRING_H_ */