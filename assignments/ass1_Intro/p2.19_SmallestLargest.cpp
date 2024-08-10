#include <iostream>
using namespace std;

/** 2.19 (Arithmetic, Smallest and Largest)
Write a program that inputs three integers from the keyboard
and prints the sum, average, product, smallest and largest of these numbers.

The screen dialog should appear as follows:

Input three different integers: 13 27 14
Sum is 54
Average is 18
Product is 4914
Smallest is 13
Largest is 27*/
int main()
{
  int number1{0};
  int number2{0};
  int number3{0};

  cout << "\x1b[1;36mInput 3 numbers:\t\x1b[1;33m";
  cin >> number1 >> number2 >> number3;

  const auto sum{number1 + number2 + number3};
  const auto average{sum / 3};
  const auto product{number1 * number2 * number3};
  int smallest{0};
  int largest{0};

  if (number1 < number2)
  {
    if (number1 < number3)
      smallest = number1;
    else if (number2 < number3)
      smallest = number2;
    else
      smallest = number3;

    if (number2 > number3)
      largest = number2;
    else
      largest = number3;
  }
  else // number2 is smaller than number1
  {
    if (number2 < number3)
      smallest = number2;
    else
      smallest = number3;

    if (number1 > number3)
      largest = number1;
    else if (number2 > number3)
      largest = number2;
    else
      largest = number3;
  }

  cout << " \x1b[22;36m Sum is:\t\t\x1b[33m" << sum << endl
       << " \x1b[22;36m Average is:\t\t\x1b[33m" << average << endl
       << " \x1b[22;36m Product is:\t\t\x1b[33m" << product << endl
       << " \x1b[22;36m Smallest is:\t\t\x1b[33m" << smallest << endl
       << " \x1b[22;36m Largest is:\t\t\x1b[33m" << largest << endl
       << "\n\n\x1b[0m";
}