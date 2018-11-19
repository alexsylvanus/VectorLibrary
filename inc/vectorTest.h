/*	File:			vectorTest.h
	Location:		/GCC_Projects/VectorLib/inc/vectorTest.h
	Time:			3:10:01 PM
	Date:			November 14, 2018
	Author:			alexs
	Description:	Run tests of the vector functions
*/

// Begin header file
#ifndef INC_VECTORTEST_H_
#define INC_VECTORTEST_H_

// Macros
#define NELEM(a) sizeof(a)/sizeof(*a)

// Includes
#include "avector.h"
#include "astring.h"

// Functions
void vTestI();
void vTestF();
void vTestD();
void vTestS();

void TestAll();

#endif /* INC_VECTORTEST_H_ */