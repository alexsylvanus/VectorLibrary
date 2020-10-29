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

// Includes
#include <stdbool.h>
#include "export.h"

// Type Definitions
typedef struct STR String_t;
LIBRARY_API typedef String_t* string_t;

// Functions
// Vector-type Functions
LIBRARY_API void append(string_t s, char value); // Add a char to the end, equivalent to push
LIBRARY_API char pop(string_t s); // Get the last value and remove it from the string
LIBRARY_API void clear(string_t* s); // Clear the string and free the memory allocated
LIBRARY_API void setNull(string_t* s);
LIBRARY_API void sPrint(string_t s); // Print the string struct to the console

// Initialization functions
LIBRARY_API void sClear(string_t s);
LIBRARY_API string_t sInit(const char* s); // Initialize string with constant character array
LIBRARY_API string_t sCopy(string_t s);
LIBRARY_API bool sEquals(string_t s, const char* literal);

// Get functions
LIBRARY_API char getC(string_t s, int index); // Get a character at a specific index
LIBRARY_API char* getStr(string_t s);
LIBRARY_API size_t getLength(string_t s);

// Manipulate functions
LIBRARY_API string_t sAdd(string_t s1, string_t s2);
LIBRARY_API string_t sAdd_c(string_t s1, string_t s2);

// Conversion functions
LIBRARY_API string_t strI(int val); // Int to string_t conversion
LIBRARY_API string_t strF(float val); // Float to string_t conversion
LIBRARY_API string_t strD(double val); // Double to string_t conversion
LIBRARY_API int iStr(string_t val);
LIBRARY_API float fStr(string_t val);
LIBRARY_API double dStr(string_t val);


#endif /* INC_ASTRING_H_ */