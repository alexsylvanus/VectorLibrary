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
	return 0;
}

