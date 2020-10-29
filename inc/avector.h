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
LIBRARY_API typedef struct VINT* vint_t;
LIBRARY_API typedef struct VFLT* vfloat_t;
LIBRARY_API typedef struct VDBL* vdouble_t;
LIBRARY_API typedef struct VSTRING* vstring_t;

// Functions
LIBRARY_API void pushi(vint_t vector, int value);
LIBRARY_API void pushf(vfloat_t vector, float value);
LIBRARY_API void pushd(vdouble_t vector, double value);
LIBRARY_API void pushs(vstring_t vector, string_t value);
LIBRARY_API void pushs_c(vstring_t vector, string_t* addr);
LIBRARY_API void pushString(vstring_t vector, const char* s);

// */
LIBRARY_API int popi(vint_t vector);
LIBRARY_API float popf(vfloat_t vector);
LIBRARY_API double popd(vdouble_t vector);
LIBRARY_API string_t pops(vstring_t vector);
// */

LIBRARY_API void cleari(vint_t vector);
LIBRARY_API void clearf(vfloat_t vector);
LIBRARY_API void cleard(vdouble_t vector);
LIBRARY_API void clears(vstring_t vector);

// Get functions
LIBRARY_API int getI(vint_t vector, int index);
LIBRARY_API float getF(vfloat_t vector, int index);
LIBRARY_API double getD(vdouble_t vector, int index);
LIBRARY_API string_t getS(vstring_t vector, int index);

// Length functions
LIBRARY_API size_t getLengthI(vint_t vector);
LIBRARY_API size_t getLengthF(vfloat_t vector);
LIBRARY_API size_t getLengthD(vdouble_t vector);
LIBRARY_API size_t getLengthS(vstring_t vector);

// Vector Print functions
LIBRARY_API void vPrintI(vint_t vector);
LIBRARY_API void vPrintF(vfloat_t vector);
LIBRARY_API void vPrintD(vdouble_t vector);
LIBRARY_API void vPrintS(vstring_t vector);

// Init Functions
LIBRARY_API vint_t vInitI(int* v, size_t n);
LIBRARY_API vfloat_t vInitF(float* v, size_t n);
LIBRARY_API vdouble_t vInitD(double* v, size_t n);
LIBRARY_API vstring_t vInitS(char* v[], size_t n);
LIBRARY_API vstring_t vInitS_Blank();

// String functions
LIBRARY_API string_t vStrI(vint_t vector);
LIBRARY_API string_t vStrF(vfloat_t vector);
LIBRARY_API string_t vStrD(vdouble_t vector);
LIBRARY_API string_t vStrS(vstring_t vector);

#endif /* INC_AVECTOR_H_ */
