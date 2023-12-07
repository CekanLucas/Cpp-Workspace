#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib> // exit prototype
#include <iomanip>
using namespace std;

/** 4.13 ( sizeof Operator)

Write a program that uses the sizeof operator to determine the sizes in bytes
of the various data types on your computer system

Write the results to the file data-size.dat,
so that you may print the results later
The results should be displayed in two-column format with the type
name in the left column and the size of the type in the right
column,

OUTPUT: sample

char                    1
unsigned char           1
short int               2
unsigned short int      2
int                     4
unsigned int            4
long int                4
unsigned long int       4
long long int           8
unsigned long long int  8
float                   4
double                  8
long double             10

[Note: The sizes of the built-in data
types on your computer might differ from those listed here.]  */

int main()
{
  ofstream outFile{"data-size.dat", ios::out};

  // exit program if unable to create file
  if (!outFile)
  { // overloaded ! operator
    cerr << "File could not be opened" << endl;
    exit(1);
  }

  char character;
  unsigned char unsignedCharacter;
  short int shortInteger;
  unsigned short int unsignedShortInteger;
  int integer;
  unsigned int unsignedInteger;
  long int longInteger;
  unsigned long int unsignedLongInteger;
  long long int doubleLongInteger;
  unsigned long long int unsignedDoubleLongInteger;
  float floatingPointValue;
  double doublePointValue;
  long double longDoublePointValue;

  outFile << setw(50) << left << "char" << sizeof(character) << endl
          << setw(50) << left << "char" << sizeof(character) << endl
          << setw(50) << left << "unsigned char" << sizeof(unsignedCharacter) << endl
          << setw(50) << left << "short int" << sizeof(shortInteger) << endl
          << setw(50) << left << "unsigned short int" << sizeof(unsignedShortInteger) << endl
          << setw(50) << left << "int" << sizeof(integer) << endl
          << setw(50) << left << "unsigned int" << sizeof(unsignedInteger) << endl
          << setw(50) << left << "long int" << sizeof(longInteger) << endl
          << setw(50) << left << "unsigned long int" << sizeof(unsignedLongInteger) << endl
          << setw(50) << left << "long long int" << sizeof(doubleLongInteger) << endl
          << setw(50) << left << "unsigned long long int" << sizeof(unsignedDoubleLongInteger) << endl
          << setw(50) << left << "float" << sizeof(floatingPointValue) << endl
          << setw(50) << left << "double" << sizeof(doublePointValue) << endl
          << setw(50) << left << "long double" << sizeof(longDoublePointValue) << endl;
}