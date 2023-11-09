#include <stdio.h>
#include <string>
#include <iomanip>
#include <sstream>
#include "Rational.h"
using namespace std;

/* Set constructor with default values set for 1/2 */
void Rational::setRational(int numerator = 1, int denominator = 2)
{
  this->numerator = numerator;
  this->denominator = denominator;
}

Rational::Rational(int numerator, int denominator)
{
  int gcd = Rational::gcd(numerator, denominator);
  Rational::setRational(numerator / gcd, denominator / gcd);
}

/** Adds two Rational numbers.
The result should be stored in reduced form */
Rational Rational::add(Rational r)
{
  int numerator = this->numerator * r.denominator + r.numerator * this->denominator;
  int denominator = this->denominator * r.denominator;
  return Rational(numerator, denominator);
}

/** Subtracts two Rational numbers
Store the result in reduced form */
Rational Rational::subtract(Rational r)
{
  int numerator = this->numerator * r.denominator - r.numerator * this->denominator;
  int denominator = this->denominator * r.denominator;
  return Rational(numerator, denominator);
}
/** Multiplies two Rational numbers
Store the result in reduced form */
Rational Rational::multiply(Rational r)
{
  int numerator = this->numerator * r.numerator;
  int denominator = this->denominator * r.denominator;
  return Rational(numerator, denominator);
}
/** Divides two Rational numbers
The result should be stored in reduced form */
Rational Rational::divide(Rational r)
{
  int numerator = this->numerator * r.denominator;
  int denominator = this->denominator * r.numerator;
  return Rational(numerator, denominator);
}

/** Returns a string representation of a
Rational number in the form a/b , where a is the
numerator and b is the denominator */
string Rational::toRationalString()
{
  ostringstream output;
  output << numerator << "/" << denominator;
  return output.str();
}

/** Returns the Rational number as a double */
double Rational::toDouble()
{
  return static_cast<double>(numerator) / denominator;
}

int Rational::gcd(int num1, int num2)
{
  while (num2 != 0)
  {
    int temp = num2;
    num2 = num1 % num2;
    num1 = temp;
  }
  return num1;
}

/** Return the numerator */
int Rational::getNumerator()
{
  return numerator;
};
/** Return the denominator */
int Rational::getDenominator()
{
  return denominator;
};