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

// Defines
#define bool 	_Bool
#define true 	1
#define false	0

// Enumerated Types
typedef enum {
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
typedef struct {
	char* month_str;
	month_e month_num;
	uint8_t days;
} month_t;

typedef struct {
	bool leap_year;
	uint16_t year;
} year_t;

typedef struct {
	month_t month;
	uint8_t day;
	year_t year;
} date_t;

// Constants
extern const month_t january;
extern const month_t february;
extern const month_t february_ly; // Leap year special case
extern const month_t march;
extern const month_t april;
extern const month_t may;
extern const month_t june;
extern const month_t july;
extern const month_t august;
extern const month_t september;
extern const month_t october;
extern const month_t november;
extern const month_t december;

// Function Declarations
void printDate(date_t date);
void initDate(date_t* date, const char* date_str);
void initYear(year_t* year, uint16_t year_num);
void incrDay(date_t* date);
void incrDays(date_t* date, uint32_t days);

#endif /* INC_ADATE_H_ */
