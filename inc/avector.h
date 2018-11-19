/*
 * avector.h
 *
 *  Created on: Aug 10, 2018
 *      Author: alexs
 */

#ifndef INC_AVECTOR_H_
#define INC_AVECTOR_H_


// Includes
#include <stdlib.h> // For the null macro
#include "astring.h"

// Defines
#define push(v, val) _Generic(v, \
		vint_t*: pushi, \
		vfloat_t*: pushf, \
		vdouble_t*: pushd)(v, val)

// Type Definitions
// typedef struct VINT Vint_t;
typedef struct VINT* vint_t;
typedef struct VFLT* vfloat_t;
typedef struct VDBL* vdouble_t;

typedef struct { // String Vector
	string_t* vstring;
	size_t length;
} vstring_t;

// Functions
void pushi(vint_t vector, int value);
void pushf(vfloat_t vector, float value);
void pushd(vdouble_t vector, double value);
void pushs(vstring_t* vector, string_t value);

// */
int popi(vint_t vector);
float popf(vfloat_t vector);
double popd(vdouble_t vector);
string_t pops(vstring_t* vector);
// */

void cleari(vint_t vector);
void clearf(vfloat_t vector);
void cleard(vdouble_t vector);
void clears(vstring_t* vector);

// Get functions
int getI(vint_t vector, int index);
float getF(vfloat_t vector, int index);
double getD(vdouble_t vector, int index);
string_t getS(vstring_t* vector, int index);

// Vector Print functions
void vPrintI(vint_t vector);
void vPrintF(vfloat_t vector);
void vPrintD(vdouble_t vector);
void vPrintS(vstring_t vector);

// Init Functions
vint_t vInitI(int* v, size_t n);
vfloat_t vInitF(float* v, size_t n);
vdouble_t vInitD(double* v, size_t n);

// String functions
string_t vStrI(vint_t vector);
string_t vStrF(vfloat_t vector);
string_t vStrD(vdouble_t vector);
string_t vStrS(vstring_t vector);

#endif /* INC_AVECTOR_H_ */
