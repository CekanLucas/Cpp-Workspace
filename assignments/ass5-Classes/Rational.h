#include <string>
#include <stdio.h>
#include <iomanip>
using namespace std;

#ifndef RATIONAL_H
#define RATIONAL_H

// #pragma once // pragma once is not a standard for all C++ compiler

/**
9.6 ( Rational Class)
Create a class called Rational for performing arithmetic with fractions
Write a program to test your class

Use integer variables to represent the private data
of the class the numerator and the denominator

Provide a constructor that enables an object of this class to be initialized
when it’s declared

The constructor should contain default
values in case no initializers are provided and should store the
fraction in reduced form.

For example, the fraction 2/4 would be stored in the object
as 1 in the `numerator` and 2 in the denominator

Provide public member functions that perform each of the following tasks:

A: add —Adds two Rational numbers.
The result should be stored in reduced form

B: subtract —Subtracts two Rational numbers
Store the result in reduced form

C: multiply —Multiplies two Rational numbers
Store the result in reduced form

D: divide —Divides two Rational numbers
The result should be stored in reduced form

E: toRationalString —Returns a string representation of a
Rational number in the form a/b , where a is the
numerator and b is the denominator

F: toDouble —Returns the Rational number as a double

In Chapter 10, you’ll learn how to overload + , - , * , / and <<
so you can write expressions like a + b , a-b , a*b , a-b and
cout << a to add, subtract, multiply, divide and output Complex objects */
class Rational
{
public:
  void setRational(int numerator, int denominator);
  Rational(int numerator, int denominator);

  /** Adds two Rational numbers.
  The result should be stored in reduced form */
  Rational add(Rational r);

  /** Subtracts two Rational numbers
  Store the result in reduced form */
  Rational subtract(Rational r);

  /** Multiplies two Rational numbers
  Store the result in reduced form */
  Rational multiply(Rational r);

  /** Divides two Rational numbers
  The result should be stored in reduced form */
  Rational divide(Rational r);

  /** Returns a string representation of a
  Rational number in the form a/b , where a is the
  numerator and b is the denominator */
  string toRationalString();

  /** Returns the Rational number as a double */
  double toDouble();

  /** Calculate the greatest common denominator in order to reduce the fraction */
  int gcd(int, int);

  // get functions
  /** Return the numerator */
  int getNumerator();
  /** Return the denominator */
  int getDenominator();

private:
  int numerator;
  int denominator;
};

#endif