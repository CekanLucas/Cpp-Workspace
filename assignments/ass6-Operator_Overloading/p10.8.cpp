/**
10.8 ( Complex Class )
Consider class Complex shown in Figs. 10.14–10.16.

The class enables operations on so-called complex numbers

These are numbers of the form:

realPart + imaginaryPart * i,

where i has the value:
        sqrt(-1)

A:
Modify the class to enable input and output of complex
numbers via overloaded >> and << operators, respectively
(you should remove the toString function from the class)

B:
Overload the multiplication operator to enable
multiplication of two complex numbers as in algebra

C:
Overload the == and != operators to allow comparisons of complex numbers

After doing this exercise, you might want to read about the
Standard Library’s complex class (from header <complex> ) */

#include <iostream>
#include <iomanip>
#include "Complex.cpp"
using namespace std;

/** Overload the `<<` and `>>` operators to input and output complex numbers  */
ostream &operator<<(ostream &output, const Complex &complex)
{
  output << fixed << setprecision(1) << complex.real << " + "
         << fixed << setprecision(1) << complex.imaginary << "i";
  return output; // enables cout << a << b << c;
}
istream &operator>>(istream &input, Complex &complex)
{
  input >> setw(3) >> complex.real;
  input.ignore(3); // skip " + "
  input >> setw(3) >> complex.imaginary;
  input.ignore(1); // skip "i"
  return input;    // enables cin >> a >> b >> c;
}

/** Overload the `*` multiplication of two complex numbers
Remember: (a + bi) * (c + di) = ac + adi + bci + bdi^2 (i = sqr(-1) so i^2 = -1)
                              = ac + (ad + bc)i + bd(-1)
                              = (ac - bd) + (ad + bc)i */
Complex Complex::operator*(const Complex &operand2) const
{
  return Complex{
      real * operand2.real - imaginary * operand2.imaginary,
      real * operand2.imaginary + imaginary * operand2.real};
}

/** Overload the == and != operators to allow comparisons of complex numbers  */
bool Complex::operator==(const Complex &operand2) const
{
  return real == operand2.real && imaginary == operand2.imaginary;
}
bool Complex::operator!=(const Complex &operand2) const
{
  return real != operand2.real || imaginary != operand2.imaginary;
}

int main()
{
  Complex x;
  Complex y{4.3, 8.2};
  Complex z{3.3, 1.1};

  cout << "\x1b[1;36mx: \x1b[22;33m" << x
       << "\n\x1b[1;36my: \x1b[22;33m" << y
       << "\n\x1b[1;36mz: \x1b[22;33m" << z << endl;

  cout << "\n\x1b[1;35my * z = \x1b[1;33m" << y * z << endl;

  if (y == y)
    cout << "\n\x1b[1;35my == y = \x1b[1;33m true" << endl;
  if (y != z)
    cout << "\x1b[1;35my != z = \x1b[1;33m true" << endl;

  x = y + z;
  cout << "\n\x1b[1;35mx = y + z:\n\x1b[1;33m"
       << x << "\x1b[22;35m = \x1b[33m" << y
       << " \x1b[1;37m+ \x1b[22;33m" << z;

  x = y - z;
  cout << "\n\n\x1b[1;35mx = y - z:\n\x1b[1;33m"
       << x << "\x1b[22;35m = \x1b[33m" << y
       << " \x1b[1;37m- \x1b[22;33m" << z << endl;

  cout << "\n\x1b[1;32mInput a complex number with form \x1b[22;31m4.3 + 8.2i\x1b[1;32m:\t\x1b[1;37m";
  cin >> x;
  cout << "\x1b[1;32mComplex number just inputted:\t\t\t\x1b[1;37m" << x << endl
       << endl;

  cout << "\x1b[0m" << endl;
}

/* EXPECTED SAMPLE OUTPUT
x: 0.0 + 0.0i
y: 4.3 + 8.2i
z: 3.3 + 1.1i

y * z = 5.2 + 31.8i

y == y =  true
y != z =  true

x = y + z:
7.6 + 9.3i = 4.3 + 8.2i + 3.3 + 1.1i

x = y - z:
1.0 + 7.1i = 4.3 + 8.2i - 3.3 + 1.1i

Input a complex number with form 4.3 + 8.2i:    3 + 2.6i
Complex number just inputted:                   3.0 + 2.6i */