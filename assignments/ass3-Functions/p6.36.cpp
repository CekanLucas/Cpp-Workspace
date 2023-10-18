#include <iostream>
using namespace std;

/**
6.36 (Recursive Exponentiation)
Write a recursive function `power(base, exponent )` that, when invoked, returns
    base^exponent

For example,  `power(3, 4) = 3 * 3 * 3 * 3`

Assume that `exponent` is an integer greater than or equal to 1

Hint: The recursion step would use the relationship
    base^exponent = base x base^(exponent-1)

and the terminating condition occurs when `exponent` is equal to `1` because
    base^1 = base */

double exponentiation(int base, int exponent);

int main()
{
  int base, power;
  cout << "\x1b[1;94mInput base and power:\t\x1b[1;33m";
  cin >> base >> power;

  cout << "\x1b[0;32mpower( \x1b[1;33m" << base
       << "\x1b[0;32m , \x1b[1;33m"
       << power << "\x1b[0;32m ) = \x1b[1;92m"
       << exponentiation(base, power) << " \x1b[0m\n" << endl;
}

double exponentiation(int base, int exponent)
{
  if (exponent == 1)
  {
    cout << base << "\x1b[0;32m = \x1b[7;35m ";
    return base;
  }
  cout << base << "\x1b[0;32m \u00D7 \x1b[1;92m";
  return base * exponentiation(base, exponent - 1);
}