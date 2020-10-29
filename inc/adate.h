/*
 * adate.h
 *
 *  Created on: Aug 6, 2018
 *      Author: alexs
 */

#ifndef INC_ADATE_H_
#define INC_ADATE_H_

// Includes
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include "export.h"

// Defines
#define bool 	_Bool
#define true 	1
#define false	0

// Enumerated Types
LIBRARY_API typedef enum {
	January = 1,
	February,
	March,
	April,
	May,
	June,
	July,
	August,
	September,
	October,
	November,
	December
} month_e;

// Structures
LIBRARY_API typedef struct {
	char* month_str;
	month_e month_num;
	uint8_t days;
} month_t;

LIBRARY_API typedef struct {
	bool leap_year;
	uint16_t year;
} year_t;

LIBRARY_API typedef struct {
	month_t month;
	uint8_t day;
	year_t year;
} date_t;

// Constants
extern LIBRARY_API const month_t january;
extern LIBRARY_API const month_t february;
extern LIBRARY_API const month_t february_ly; // Leap year special case
extern LIBRARY_API const month_t march;
extern LIBRARY_API const month_t april;
extern LIBRARY_API const month_t may;
extern LIBRARY_API const month_t june;
extern LIBRARY_API const month_t july;
extern LIBRARY_API const month_t august;
extern LIBRARY_API const month_t september;
extern LIBRARY_API const month_t october;
extern LIBRARY_API const month_t november;
extern LIBRARY_API const month_t december;

// Function Declarations
LIBRARY_API void printDate(date_t date);
LIBRARY_API void initDate(date_t* date, const char* date_str);
LIBRARY_API void initYear(year_t* year, uint16_t year_num);
LIBRARY_API void incrDay(date_t* date);
LIBRARY_API void incrDays(date_t* date, uint32_t days);

#endif /* INC_ADATE_H_ */
