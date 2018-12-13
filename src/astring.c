/*	File:			astring.c
	Location:		/GCC_Projects/VectorLib/src/astring.c
	Time:			12:20:52 PM
	Date:			November 15, 2018
	Author:			alexs
	Description:	Function Definitions for astring library
*/

// Includes
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../inc/astring.h"
#include "../inc/privateTypes.h"

// Functions
/* ==== Private Functions ==== */ // Note: These do not work, something to do with the allocation of the char pointer
size_t iStrLength(int val) {
	// Declare variables
	char* c; // Unused, ptr needed for snprintf function
	size_t n = snprintf(c, sizeof c, "%d", val);

	// Return size
	return n;
}
size_t fStrLength(float val) {
	// Declare variables
	char* c; // Unused, ptr needed for snprintf function
	size_t n = snprintf(c, sizeof c, "%f", val);

	// Return size
	return n;
}
int dStrLength(double val) {
	// Declare variables
	char c[10]; // Unused, ptr needed for snprintf function
	int n = snprintf(c, sizeof(c), "%f", val);
	printf("%d chars needed\n", n);
	// Return size
	return n;
}

/* ==== Public Functions ==== */ // Don't worry, these work
// Vector-type functions
void append(string_t s, char value) {
	// Determine if vector contains any values or not
	if (s->length == 0) {
		s->str = (char*)calloc(2, sizeof(char));
		*s->str = value;
		*(s->str + 1) = '\0';
		s->length = 1;
	}
	else {
		s->length++;
		s->str = (char*)realloc(s->str, sizeof(char)*(s->length+1));
		*(s->str + s->length - 1) = value;
		*(s->str + s->length) = '\0';
	}
}
char pop(string_t s) {
	char val = '\0';
	if (s->length > 0) {
		s->length--;
		val = *(s->str + s->length);
		s->str = (char*)realloc(s->str, sizeof(char)*s->length);
	}
	return val;
}
void clear(string_t s) {
	// Check if the pointer has already been cleared
	if (s != NULL) {
		s->length = 0;
		free(s->str);
		s->str = NULL;
		free(s);
		s = NULL;	
	}
}
void sPrint(string_t s) {
	printf(s->str);
}

// Debugging function, use clear() instead
void sClear(string_t s) {
	s->length = 0;
	printf("Deallocating address 0x%X\n", s->str);
	free(s->str);
	s->str = NULL;
	printf("Deallocating address 0x%X\n", s);
	free(s);
}

// Initialization functions
string_t sInit(const char* s) {
	// Declare variables
	String_t temp = EMPTY;
	string_t ret = (String_t*)malloc(sizeof(String_t));
	*ret = temp;
	// Loop through string
	int i = 0;
	for (i = 0; i < strlen(s); i++) {
		append(ret, *(s+i));
	}

	// Return String
	return ret;
}
string_t sCopy(string_t s) {
	// Declare variables
	String_t temp = EMPTY;
	string_t ret = (String_t*)malloc(sizeof(String_t));
	*ret = temp;

	// Loop through string
	int i = 0;
	for (i = 0; i < s->length; i++) {
		append(ret, getC(s, i));
	}
	return ret;
}
bool sEquals(string_t s, const char* literal) {
	/* Compare the pointer of s to the literal string */
	return strcmp(s->str, literal);
}

// Get functions
char getC(string_t s, int index) {
	// Declare variables
	char ret = '\0';
	
	// Make sure index is within the range of the vector
	if (index < s->length) {
		ret = *(s->str+index); // Get the char at the address shifted by the index 
	}
	// Return char
	return ret;
}
char* getStr(string_t s) {
	return s->str;
}
size_t getLength(string_t s) {
	return s->length;
}

// Manipulation Function
string_t sAdd(string_t s1, string_t s2) {
	// Get size of new string
	int n = getLength(s1) + getLength(s2);
	char s[n];
	// Check if size makes sense
	if (n > s1->length && n > s2->length) {
		// Write strings to new character arrays
		sprintf(s, "%s%s", getStr(s1), getStr(s2));
	}
	else if(n == s1->length) {
		sprintf(s, "%s", getStr(s1));
	}
	else if(n == s2->length) {
		sprintf(s, "%s", getStr(s2));
	}
	else {
		return NULL; // The case that both strings are empty
	}

	// Convert character array to string object and return
	return sInit(s);
}
string_t sAdd_c(string_t s1, string_t s2) {
	// Get size of new string
	int n = getLength(s1) + getLength(s2);
	char s[n];
	// Check if size makes sense
	if (n > s1->length && n > s2->length) {
		// Write strings to new character arrays
		sprintf(s, "%s%s", getStr(s1), getStr(s2));
	}
	else if(n == s1->length) {
		sprintf(s, "%s", getStr(s1));
	}
	else if(n == s2->length) {
		sprintf(s, "%s", getStr(s2));
	}
	else {
		return NULL; // The case that both strings are empty
	}

	// Clear the strings passed to the function
	clear(s1);
	clear(s2);

	// Convert character array to string object and return
	return sInit(s);
}

// Conversion functions
string_t strI(int val) {
	// Declare variables
	char c[20]; 
	size_t n = snprintf(c, sizeof(c), "%d", val);

	// Allocate array with size of the float string
	char s[n];

	// Write float to character array
	sprintf(s, "%d", val);

	// Create a string object
	string_t ret = sInit(s);
	return ret;
}
string_t strF(float val) {
	// Declare variables
	char c[20]; 
	size_t n = snprintf(c, sizeof(c), "%f", val);

	// Allocate array with size of the float string
	char s[n];

	// Write float to character array
	sprintf(s, "%f", val);

	// Create a string object
	string_t ret = sInit(s);
	return ret;
}
string_t strD(double val) {
	// Declare variables
	char c[20]; 
	size_t n = snprintf(c, sizeof(c), "%f", val);

	// Allocate array with size of the float string
	char s[n];

	// Write float to character array
	sprintf(s, "%f", val);

	// Create a string object
	string_t ret = sInit(s);
	return ret;
}