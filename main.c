/*	File:			main.c
	Location:		/GCC_Projects/VectorLib/main.c
	Time:			6:56:01 PM
	Date:			Jul 24, 2018
	Author:			alexs
	Description:	Runs the vectorTest TestAll function
*/

// Includes
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "adate.h"
#include "vectorTest.h"
#include "export.h"
#include "avector.h"

// Variable Type Definitions

// Struct Type Definitions

// Enum Type Definitions

// Global Variables

// Functions

int main() {
	year_t yr;
	initYear(&yr, 1996);
	date_t birthday = {
			march,
			13,
			yr
	};

	printDate(birthday);
	printf("\n");

	TestAll();
	string_t str = sInit("");
	clear(&str);

	printf("\nTesting initialize and clear empty vectors.\n");
	vint_t vector_int = vInitI(NULL, 0);
	cleari(vector_int);
	cleari(vector_int);

	vfloat_t vector_float = vInitF(NULL, 0);
	clearf(vector_float);
	clearf(vector_float);

	vdouble_t vector_double = vInitD(NULL, 0);
	cleard(vector_double);

	vstring_t vector_string = vInitS_Blank();
	clears(vector_string);
	clears(vector_string);

	printf("\nSuccess! Clear can be called multiple times on the same vector. \n");
	return 0;
}

