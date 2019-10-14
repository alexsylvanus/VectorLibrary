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
typedef struct VSTRING Vstring_t;

// Structs
struct STR { // String Type
	char* str;
	size_t length;
};

struct VINT { // Integer Vector Type
	int* vint;
	size_t length;
};

struct VFLT { // Float Vector Type
	float* vfloat;
	size_t length;
};

struct VDBL { // Double Vector Type
	double* vdouble;
	size_t length;
};

struct VSTRING{ // String Vector
	string_t* vstring;
	size_t length;
};