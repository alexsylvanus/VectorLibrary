/*	File:			adate.c
	Location:		/GCC_Projects/VectorLib/src/adate.c
	Time:			1:00:19 PM
	Date:			Aug 7, 2018
	Author:			alexs
	Description:	Definitions of date functions from date.h
*/

// Includes
#include "../inc/adate.h"


// Global variables
const month_t january = {"January", January, 31};
const month_t february = {"February", February, 28};
const month_t february_ly = {"February", February, 29}; // Leap year special case
const month_t march = {"March", March, 31};
const month_t april = {"April", April, 30};
const month_t may = {"May", May, 31};
const month_t june = {"June", June, 30};
const month_t july = {"July", July, 31};
const month_t august = {"August", August, 31};
const month_t september = {"September", September, 30};
const month_t october = {"October", October, 31};
const month_t november = {"November", November, 30};
const month_t december = {"December", December, 31};

year_t f;
// Functions
void printDate(date_t date) {
	// Unfinished
	char* month_loc = date.month.month_str;
	printf(month_loc);
	uint8_t day_loc = date.day;
	printf(" %u", day_loc);
	uint16_t year_loc = date.year.year;
	printf(" %u", year_loc);

}

void initDate(date_t* date, const char* date_str) {
	// Unfinished

}

void initYear(year_t* year, uint16_t year_num) {
	if (year_num%4 != 0) {
		// Common year
		year->leap_year = false;
	}
	else if (year_num%100 != 0) {
		// Leap year
		year->leap_year = true;
	}
	else if (year_num%400 != 0) {
		// Common year
		year->leap_year = false;
	}
	else {
		// Leap year
		year->leap_year = true;
	}
	year->year = year_num;
}

void incrDay(date_t* date) {
	// Unfinished

}
void incrDays(date_t* date, uint32_t days) {
	// Unfinished

}

