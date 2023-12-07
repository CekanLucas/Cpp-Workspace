#include <iostream>
#include <iomanip>

using namespace std;

/** 3.12 (Converting Fahrenheit to Celsius)

Write a program that converts integer Fahrenheit temperatures
from 0 to 212 degrees to floating-point Celsius temperatures
with 3 digits of precision

Use the formula `celsius = 5.0 / 9.0 * (fahrenheit - 32);`
to perform the calculation

The output should be printed in two right-justified columns and the Celsius temperatures
should be preceded by a sign for both positive and negative values  */

int main()
{
  int width{16};
  int fahrenheit;
  cout << "\x1b[1;34mPlease enter a value in Fahrenheit: \x1b[1;33m";
  cin >> fahrenheit;
  // cout << endl;
  cout << "\x1b[0;1;32;21m" << endl;

  double celsius = 5.0 / 9.0 * (fahrenheit - 32);

  cout << setw(width) << right << "Fahrenheit"
       << setw(width) << right << "Celsius" << endl;
  cout << "\x1b[0;92m";
  cout << fixed << setprecision(3) << setw(width) << right << fahrenheit
       << fixed << setprecision(3) << setw(width) << right << showpos << celsius << endl;

  cout << "\x1b[0m" << endl;
}