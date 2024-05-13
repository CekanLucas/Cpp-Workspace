/* 2.16 (Arithmetic)
Write a program that asks the user to enter two numbers,
obtains the two numbers from the user and prints
the sum, product, difference, and quotient of the two numbers. */

#include <iostream>

using namespace std;

int main()
{
  int number1{0};
  int number2{0};

  cout << "\x1b[1;36mInput 2 numbers:\t\x1b[1;33m";
  cin >> number1 >> number2;

  cout << " \x1b[22;36m sum:\t\t\t\x1b[33m"
    << number1 << " + " << number2 << " = " 
    << "\x1b[1;35m"<< number1 + number2 << endl
    << " \x1b[22;36m product:\t\t\x1b[33m"
    << number1 << " * " << number2 << " = " 
    << "\x1b[1;35m"<< number1 * number2 << endl
    << " \x1b[22;36m difference:\t\t\x1b[33m"
    << number1 << " - " << number2 << " = " 
    << "\x1b[1;35m"<< number1 - number2 << endl
    << " \x1b[22;36m quotient:\t\t\x1b[33m"
    << number1 << " / " << number2 << " = " 
    << "\x1b[1;35m"<< number1 / number2 << endl
    << "\n\n\x1b[0m";
}