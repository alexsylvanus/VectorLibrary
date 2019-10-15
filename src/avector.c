/*	File:			avector.c
	Location:		/GCC_Projects/VectorLib/src/avector.c
	Time:			11:40:58 AM
	Date:			Aug 10, 2018
	Author:			alexs
	Description:	Function Definitions for vector library
*/

// Includes
#include <stdio.h>
#include <string.h>
#include "../inc/avector.h"
#include "../inc/privateTypes.h"

// Defines
#define DEFAULT_VECTOR EMPTY
// Variable Type Definitions

// Struct Type Definitions

// Enum Type Definitions

// Global Variables

// Functions

/* ==== Public Functions ==== */
void pushi(vint_t vector, int value) {
	// Determine if vector contains any values or not
	if (vector->length == 0) {
		vector->vint = (int*)calloc(1, sizeof(int));
		*vector->vint = value;
		vector->length = 1;
	}
	else {
		vector->length++;
		vector->vint = (int*)realloc(vector->vint, sizeof(int)*vector->length);
		*(vector->vint + vector->length - 1) = value;
	}
}
void pushf(vfloat_t vector, float value) {
	// Determine if vector contains any values or not
	if (vector->length == 0) {
		vector->vfloat = (float*)calloc(1, sizeof(float));
		*vector->vfloat = value;
		vector->length = 1;
	}
	else {
		vector->length++;
		vector->vfloat = (float*)realloc(vector->vfloat, sizeof(float)*vector->length);
		*(vector->vfloat + vector->length - 1) = value;
	}
}
void pushd(vdouble_t vector, double value) {
	// Determine if vector contains any values or not
	if (vector->length == 0) {
		vector->vdouble = (double*)calloc(1, sizeof(double));
		*vector->vdouble = value;
		vector->length = 1;
	}
	else {
		vector->length++;
		vector->vdouble = (double*)realloc(vector->vdouble, sizeof(double)*vector->length);
		*(vector->vdouble + vector->length - 1) = value;
	}
}
void pushs(vstring_t vector, string_t value) { // This version does not clear the passed string
	if (vector->length == 0) {
		vector->vstring = (string_t*)calloc(1, sizeof(string_t));
		*vector->vstring = sCopy(value);
		// clear(&value);
		vector->length = 1;
	}
	else {
		vector->length++;
		vector->vstring = (string_t*)realloc(vector->vstring, sizeof(string_t)*vector->length);
		*(vector->vstring + vector->length - 1) = sCopy(value);
		// clear(&value);
	}
}
void pushs_c(vstring_t vector, string_t* addr) { // This version will clear the input string value
	// Determine if vector contains any values or not
	if (vector->length == 0) {
		// Allocate memory for pointer to the vector
		vector->vstring = (string_t*)calloc(1, sizeof(string_t));
		*vector->vstring = sCopy(*addr);

		// Clear the passed string parameter
		clear(addr);
		vector->length = 1;
	}
	else {
		vector->length++;
		vector->vstring = (string_t*)realloc(vector->vstring, sizeof(string_t)*vector->length);
		*(vector->vstring + vector->length - 1) = sCopy(*addr);
		clear(addr);
	}
}
void pushString(vstring_t vector, const char* s) {
	// Converts 's' to defined string_t type
	string_t val = sInit(s);
	pushs_c(vector, &val); // This takes care of clearing the temporary string_t val
}

// Pop Functions
int popi(vint_t vector) {
	int val = 0;
	if (vector->length > 0) {
		vector->length--;
		val = *(vector->vint + vector->length);
		vector->vint = (int*)realloc(vector->vint, sizeof(int)*vector->length);
	}
	return val;
}
float popf(vfloat_t vector) {
	float val = 0;
	if (vector->length > 0) {
		vector->length--;
		val = *(vector->vfloat + vector->length);
		vector->vfloat = (float*)realloc(vector->vfloat, sizeof(float)*vector->length);
	}
	return val;
}
double popd(vdouble_t vector) {
	double val = 0;
	if (vector->length > 0) {
		vector->length--;
		val = *(vector->vdouble + vector->length);
		vector->vdouble = (double*)realloc(vector->vdouble, sizeof(double)*vector->length);
	}
	return val;
}
string_t pops(vstring_t vector) {
	string_t val = NULL;
	if (vector->length > 0) {
		vector->length--;
		val = sCopy(*(vector->vstring + vector->length));
		clear(&(*(vector->vstring + vector->length))); 
		vector->vstring = (string_t*)realloc(vector->vstring, sizeof(string_t)*vector->length);
	}
	return val;
}

// Clear Functions
void cleari(vint_t vector) {
	vector->length = 0;
	free(vector->vint);
	vector->vint = NULL;
	free(vector);
}
void clearf(vfloat_t vector) {
	vector->length = 0;
	free(vector->vfloat);
	vector->vfloat = NULL;
	free(vector);
}
void cleard(vdouble_t vector) {
	vector->length = 0;
	free(vector->vdouble);
	vector->vdouble = NULL;
	free(vector);
}
void clears(vstring_t vector) {
	// Deallocate the char pointers
	int i = 0;
	for(i = 0; i < vector->length; i++) {
		clear(&(*(vector->vstring + i)));
	}
	// Deallocate the string pointer
	vector->length = 0;
	free(vector->vstring);
	vector->vstring = NULL;
	free(vector);
}

// Get Functions
int getI(vint_t vector, int index) {
	// Declare variables
	int ret = 0;
	
	// Make sure index is within the range of the vector
	if (index < vector->length) {
		ret = *(vector->vint+index); // Get the value at the address shifted by the index 
	}
	// Return value
	return ret;
}
float getF(vfloat_t vector, int index) {
	// Declare variables
	float ret = 0;
	
	// Make sure index is within the range of the vector
	if (index < vector->length) {
		ret = *(vector->vfloat+index); // Get the value at the address shifted by the index 
	}

	// Return value
	return ret;
}
double getD(vdouble_t vector, int index) {
	// Declare variables
	double ret = 0;
	
	// Make sure index is within the range of the vector
	if (index < vector->length) {
		ret = *(vector->vdouble+index); // Get the value at the address shifted by the index 
	}
	// Return value
	return ret;
}
string_t getS(vstring_t vector, int index) {
	/* Instead of returning the pointer at the index specified, 
	this function will make a copy of the string stored at the index and return 
	a pointer to that string object. This means that the pointer returned must be cleared
	using the astring.h 'clear()' method. It also means that manipulating the returned string
	will not manipulate the vector. */

	// Declare variables
	string_t ret = NULL;

	// Make sure index is within range of the vector
	if (index < vector->length) {
		ret = sCopy(*(vector->vstring+index));
	}
	// Return value
	return ret;
}

// Length functions
size_t getLengthI(vint_t vector) {
	// @:TODO
	return 0;
}
size_t getLengthF(vfloat_t vector) {
	// @:TODO
	return 0;
}
size_t getLengthD(vdouble_t vector) {
	// @:TODO
	return 0;
}
size_t getLengthS(vstring_t vector) {
	// Declare variables
	size_t len = 0;

	// Check if vector cleared
	len = (vector==NULL) ? 0 : vector->length;

	// Return the variable
	return len;
}

// Vector Print Functions
void vPrintI(vint_t vector) {
	// Check if vector contains data
	if (vector->length > 0) {
		// Print values seperated by commas
		int i = 0;
		for (i = 0; i < vector->length - 1; i++) {
			printf("%d, ", *(vector->vint+i));
		}
		printf("%d", *(vector->vint+i)); // Print last value not followed by comma
	}
	else {
		// Inform user that vector is empty
		printf("Empty Vector\n");
	}
}
void vPrintF(vfloat_t vector) {
	// Check if vector contains data
	if (vector->length > 0) {
		// Print values seperated by commas
		int i = 0;
		for (i = 0; i < vector->length - 1; i++) {
			printf("%f, ", *(vector->vfloat+i));
		}
		printf("%f", *(vector->vfloat+i)); // Print last value not followed by comma
	}
	else {
		// Inform user that vector is empty
		printf("Empty Vector\n");
	}
}
void vPrintD(vdouble_t vector) {
	// Check if vector contains data
	if (vector->length > 0) {
		// Print values seperated by commas
		int i = 0;
		for (i = 0; i < vector->length - 1; i++) {
			printf("%f, ", *(vector->vdouble+i));
		}
		printf("%f", *(vector->vdouble+i)); // Print last value not followed by comma
	}
	else {
		// Inform user that vector is empty
		printf("Empty Vector\n");
	}
}
void vPrintS(vstring_t vector) {
	// Check if vector contains data
	if (vector->length > 0) {
		// Print values seperated by commas
		int i = 0;
		for (i = 0; i < vector->length - 1; i++) {
			printf("%s, ", (*(vector->vstring+i))->str);
		}
		printf("%s", (*(vector->vstring+i))->str); // Print last value not followed by comma
	}
	else {
		// Inform user that vector is empty
		printf("Empty Vector\n");
	}
}

// Init functions
vint_t vInitI(int* v, size_t n) { // n is passed using the NELEM macro of v in the test
    // Declare variables
	Vint_t temp = DEFAULT_VECTOR;
    vint_t val = (Vint_t*)malloc(sizeof(Vint_t));
    *val = temp;

    // Loop through array
    int i = 0;
    for (i = 0; i<n; i++) {
        pushi(val, *(v+i));
        //printf("%d\n", *(v+i));
    }
    
    // Return val
    return val;
}
vfloat_t vInitF(float* v, size_t n) { // n is passed using the NELEM macro of v in the test
    // Declare variables
	Vfloat_t temp = DEFAULT_VECTOR;
    vfloat_t val = (Vfloat_t*)malloc(sizeof(Vfloat_t));
    *val = temp;

    // Loop through array
    int i = 0;
    for (i = 0; i<n; i++) {
        pushf(val, *(v+i));
        //printf("%f\n", *(v+i));
    }
    
    // Return val
    return val;
}
vdouble_t vInitD(double* v, size_t n) { // n is passed using the NELEM macro of v in the test
    // Declare variables
	Vdouble_t temp = DEFAULT_VECTOR;
    vdouble_t val = (Vdouble_t*)malloc(sizeof(Vdouble_t));
    *val = temp;

    // Loop through array
    int i = 0;
    for (i = 0; i<n; i++) {
        pushd(val, *(v+i));
        //printf("%f\n", *(v+i));
    }
    
    // Return val
    return val;
}
vstring_t vInitS(char* v[], size_t n) {
	// Declare variables
	Vstring_t temp = DEFAULT_VECTOR;
	vstring_t val = (Vstring_t*)malloc(sizeof(Vstring_t));
	*val = temp;

	// Loop through array
	int i = 0;
	for (i = 0; i<n; i++) {
		pushString(val, *(v+i));
	}

	// Return val
	return val;
}

vstring_t vInitS_Blank() {
	// Declare variables
	Vstring_t temp = DEFAULT_VECTOR;
	vstring_t val = (Vstring_t*)malloc(sizeof(Vstring_t));
	*val = temp;

	// Return val
	return val;
}

// String functions
string_t vStrI(vint_t vector) {
	// Declare return string
	string_t S = sInit("");
	string_t sTemp = NULL;
	// Check if vector contains data
	if (vector->length > 0) {
		// Print values seperated by commas
		int i = 0;
		for (i = 0; i < vector->length - 1; i++) {
			sTemp = strI(getI(vector, i));
			S = sAdd_c(S, sAdd_c(sTemp, sInit(", ")));
			// printf("%d, ", *(vector->vint+i));
		}
		S = sAdd_c(S, strI(getI(vector, i)));
		// printf("%d", *(vector->vint+i)); // Print last value not followed by comma
	}
	// Return string
	return S;
}
string_t vStrF(vfloat_t vector) {
	// Declare return string
	string_t S = sInit("");
	string_t sTemp = NULL;
	// Check if vector contains data
	if (vector->length > 0) {
		// Print values separated by commas
		int i = 0;
		for (i = 0; i < vector->length - 1; i++) {
			sTemp = strF(getF(vector, i));
			S = sAdd_c(S, sAdd_c(sTemp, sInit(", ")));
		}
		S = sAdd_c(S, strF(getF(vector, i)));
	}
	return S;
}

// @:TODO
/*
string_t vStrF(vfloat_t vector);
string_t vStrD(vdouble_t vector);
string_t vStrS(vstring_t vector);
//*/
