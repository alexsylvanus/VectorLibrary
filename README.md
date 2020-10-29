# VectorLibrary
Simple dynamic memory allocation library for C.

## How to use
To compile the shared library, run:
```
make library
```

To compile the test, run:
```
make
```

### Include
To use functions in external project include the library by adding the include:
```C
#include "vector_library.h"
```

## Available Functions
### In `"astring.h"`

**Function:** `void append(string_t s, char value);`  
**Description:** Adds the character specified by `value` to the end of the the string `s`.  
  
**Function:** `char pop(string_t s);`  
**Description:** Return the last character in string `s` and remove the character from the string.  
  
**Function:** `void clear(string_t* s);`  
**Description:** Clears the string and frees the memory.  
  
**Function:** `void setNull(string_t* s);`  
**Description:** Sets the string pointer to `NULL`.  
  
**Function:** `void sPrint(string_t s);`  
**Description:** Prints the string to the console.  
  
**Function:** `string_t sInit(const char* s);`  
**Description:** Initialize the string with a constant character array.  
  
**Function:** `string_t sCopy(string_t s);`  
**Description:** Copies `s` into new `string_t` Both strings need to be cleared.  
  
**Function:** `bool sEquals(string_t s, const char* literal);`  
**Description:** Compares the strings, returns `true` if the strings are equivalent.  
  
**Function:** `char getC(string_t s, int index);`  
**Description:** Returns the character at specified `index`.  
  
**Function:** `char* getStr(string_t s);`  
**Description:** Returns the `string_t` as a standard character array.  
  
**Function:** `size_t getLength(string_t s);`  
**Description:** Returns the length of the string.  
  
**Function:** `string_t sAdd(string_t s1, string_t s2);`  
**Description:** Returns both inputs in a single string one after the other. A concatenate function.  
  
**Function:** `string_t sAdd_c(string_t s1, string_t s2);`  
**Description:** Same as above `sAdd(string_t, string_t)`, but runs `clear(string_t)` on both input strings.  
  
**Function:** `string_t strI(int val);`  
**Description:** Returns the integer `val` as a `string_t`.  
  
**Function:** `string_t strF(float val);`  
**Description:** Returns the float `val` as a `string_t`.  
  
**Function:** `string_t strD(double val);`  
**Description:** Returns the double `val` as a `string_t`.  
  
### In `"avector.h"`
#### Naming conventions:
There are four types of vectors included; int, float, double, and string_t. The functions are named according the the type. A specifying character is placed after the function name. The specifying characters are as follows:  
- int->'i'
- double->'d'
- float->'f'
- string_t->'s'  
So a function named `func` to be used for an `int` would be called:
```C
funci();
```
Any function with an '_c' at the end means the function will clear the input vector.  
  

**Function:** `push(vector, value)`
```C++
void pushi(vint_t vector, int value);
void pushf(vfloat_t vector, float value);
void pushd(vdouble_t vector, double value);
void pushs(vstring_t vector, string_t value);
```
**Description:** Places the input `value` at the end of the vector.  
  
**Function:** `pushs_c(vstring_t vector, string_t* addr)`  
**Description:** Puts `string_t` pointed to by `addr` at the end of the vector. Clears the input address.  
  

**Function:** `pop(vector)`
```C++
int popi(vint_t vector);
float popf(vfloat_t vector);
double popd(vdouble_t vector);
string_t pops(vstring_t vector);
```
**Description:** Returns the last element of `vector` and removes it from `vector`.  
  
**Function:** `clear(vector)`
```C++
void cleari(vint_t vector);
void clearf(vfloat_t vector);
void cleard(vdouble_t vector);
void clears(vstring_t vector);
```
**Description:** Clears the memory allocated to `vector`.  
  
**Function:** `get(vector, index)`
```C++
int geti(vint_t vector, int index);
float getf(vfloat_t vector, int index);
double getd(vdouble_t vector, int index);
string_t gets(vstring_t vector, int index);
```
**Description:** Returns the element of `vector` at `index`.  
  
**Function:** `getLength(vector)`
```C++
size_t getLengthi(vint_t vector);
size_t getLengthf(vfloat_t vector);
size_t getLengthd(vdouble_t vector);
size_t getLengths(vstring_t vector);
```
**Description:** Returns the length of `vector`.  
  
**Function:** `vPrint(vector)`
```C++
void vPrinti(vint_t vector);
void vPrintf(vfloat_t vector);
void vPrintd(vdouble_t vector);
void vPrints(vstring_t vector);
```
**Description:** Prints comma separated values to the console of `vector`.  
  
**Function:** `vInit(v, n)`
```C++
vint_t vIniti(int* v, size_t n);
float vInitf(float* v, size_t n);
double vInitd(double* v, size_t n);
string_t vInits(char* v[], size_t n);
```
**Description:** Creates a new vector type from standard C array type.  
  
**Function:** `vStr(vector)`
```C++
string_t vStri(vint_t vector);
string_t vStrf(vfloat_t vector);
string_t vStrd(vdouble_t vector);
string_t vStrs(vstring_t vector);
```
**Description:** Returns `string_t` containing comma separated values.  
  
## Sample Code
```C++
/* This code shows how to properly create the vector types, as well as clear them after use. */
string_t str = sInit("");
clear(&str);

vint_t vector_int = vIniti({}, 0);
cleari(vector_int);

vfloat_t vector_float = vInitf({}, 0);
clearf(vector_float);

vdouble_t vector_double = vInitd({}, 0);
cleard(vector_double);

vstring_t vector_string = vInitS_Blank();
clears(vector_string);
```
