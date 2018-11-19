/*	File:			privateTypes.h
	Location:		/GCC_Projects/VectorLib/inc/privateTypes.h
	Time:			3:08:35 PM
	Date:			November 15, 2018
	Author:			alexs
	Description:	Private Structures for String library
*/
#include <stdlib.h>

// Defines
#define EMPTY {NULL, 0}

// Type Definitions
typedef struct VINT Vint_t;
typedef struct VFLT Vfloat_t;
typedef struct VDBL Vdouble_t;

// Structs
struct STR { // String Type
	char* str;
	size_t length;
};

struct VINT {
	int* vint;
	size_t length;
};

struct VFLT {
	float* vfloat;
	size_t length;
};

struct VDBL {
	double* vdouble;
	size_t length;
};