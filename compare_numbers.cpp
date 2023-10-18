/* Comparing integers using if statements
   and relational/equality operators */

#include <iostream> // enables program to output data to the screen

using std::cin;  // program uses cin
using std::cout; // program uses cout
using std::endl; // program uses endl

// function main begins program execution
int main()
{
  int number1{0}; // first  integer to compare  (initalized to 0)
  int number2{0}; // second integer to compare  (initalized to 0)

  cout << "Enter two integers to compare:\t"; // prompt user for data
  cin >> number1 >> number2;                  // read two integers from user

  if (number1 != number2)
    cout << number1 << " != " << number2 << endl;

  if (number1 < number2)
    cout << number1 << " < " << number2 << endl;

  if (number1 > number2)
  {
    cout << number1 << " > " << number2 << endl;
  }

  if (number1 <= number2)
  {
    cout << number1 << " <= " << number2 << endl;
  }

  if (number1 >= number2)
  {
    cout << number1 << " >= " << number2 << endl;
  }

} // end function main