/*	File:			vectorTest.c
	Location:		/GCC_Projects/VectorLib/src/vectorTest.c
	Time:			3:30:17 PM
	Date:			November 14, 2018
	Author:			alexs
	Description:	Run tests of the vector functions
*/

// Includes
#include "../inc/vectorTest.h"
#include <stdio.h>

// Functions
void vTestI() {
    // Print Name
    printf("\n ---- Integer Vector Test ----\n");

    // Initialize vector
    int arr[] = {-13, 20, 37, 15, -9, -11, 25, 21};
    vint_t v = vInitI(arr, NELEM(arr));

    // Test Print
    printf("Array = ");
    vPrintI(v);
    printf("\n");

    string_t S = vStrI(v);
    printf("Array = %s\n", getStr(S));
    clear(S);

    // Test the get function
    printf("Third Element: %d\n", getI(v, 2));

    // Test the Pop function
    printf("Last Element: %d\n", popi(v));

    string_t s = strI(popi(v));
    printf("Last Element: %s\n", getStr(s));
    clear(s);

    printf("Array = ");
    vPrintI(v);
    printf("\n");

    // Clear the array
    cleari(v);
    printf("Vector Cleared\n ---- Test Finished ----\n");
}
void vTestF() {
    // Print Name
    printf("\n ---- Float Vector Test ----\n");

    // Initialize vector
    float arr[] = {-1.3, 20.985, 37.375, 1.695, -6.899, -3.11, 25.34, 1.821};
    vfloat_t v = vInitF(arr, NELEM(arr));

    // Test Print
    printf("Array = ");
    vPrintF(v);
    printf("\n");

    // Test the get function
    printf("Third Element: %f\n", getF(v, 2));

    // Test the Pop function
    printf("Last Element: %f\n", popf(v));

    string_t s = strF(popf(v));
    printf("Last Element: %s\n", getStr(s));
    clear(s);

    printf("Array = ");
    vPrintF(v);
    printf("\n");

    // Clear the array
    clearf(v);
    printf("Vector Cleared\n ---- Test Finished ----\n");
}
void vTestD() {
    // Print Name
    printf("\n ---- Double Vector Test ----\n");

    // Initialize vector
    double arr[] = {-1.3000058, 20.992785, 37.251375, -6.84499, -3.17751, 25.3264};
    vdouble_t v = vInitD(arr, NELEM(arr));

    // Test Print
    printf("Array = ");
    vPrintD(v);
    printf("\n");

    // Test the get function
    printf("Third Element: %f\n", getD(v, 2));

    // Test the Pop function
    printf("Last Element: %f\n", popd(v));

    string_t s = strD(popd(v));
    printf("Last Elements: %s\n", getStr(s));
    clear(s);

    printf("Array = ");
    vPrintD(v);
    printf("\n");

    // Clear the array
    cleard(v);
    printf("Vector Cleared\n ---- Test Finished ----\n");
}
void vTestS() {
    // Print Name
    printf("\n ---- String Vector Test ----\n");

    // Initialize Vector
    char* arr[] = {"Hello", "Alex", "Syl", "va", "nus", "I am a computer." };
    vstring_t v = vInitS(arr, NELEM(arr));
    printf("Strings Initialized\n");
    
    // Test Print
    printf("Array = ");
    vPrintS(v);
    printf("\n");

    // Test the get function
    string_t s = getS(v, 2);
    printf("Third Element: %s\n", getStr(s));
    clear(s);

    // Test Pop function
    clear(pops(v)); // Pop without printing

    string_t S1 = pops(v);
    printf("Last Element: ");
    sPrint(S1);
    printf("\n");

    string_t S2 = pops(v);
    printf("Last Element: ");
    sPrint(S2);
    printf("\n");

    string_t S3 = pops(v);
    printf("Array = ");
    vPrintS(v);
    printf("\n");

    // Test string add function
    string_t S = sAdd_c(S3, sAdd_c(S2, S1));
    printf("Concatenated String of Popped strings: %s\n", getStr(S));
    clear(S);

    //*/
    // Clear the array
    clears(v);
    printf("Vector Cleared\n ---- Test Finished ----\n");
}

void TestAll() {
    // Run all tests
    vTestI();
    vTestF();
    vTestD();
    vTestS();
}