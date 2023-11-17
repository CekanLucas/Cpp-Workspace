#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
using namespace std;

/**
10.10 ( RationalNumber Class )
Create a RationalNumber (fractions) class like the one in Exercise 9.6.

Provide the following capabilities:

A:  Create a constructor that prevents a 0 denominator in a fraction,
    reduces or simplifies fractions that are not in reduced form
    and avoids negative denominators

B: Overload the addition, subtraction, multiplication and division operators for this class

C: Overload the relational and equality operators for this class */
class RationalNumber
{
public:
  /* Prevent 0 denominator and reduce or simplify fraction */
  RationalNumber(int numerator, int denominator)
  {
    int gcdValue = gcd(numerator, denominator);
    setRationalNumber(numerator / gcdValue, denominator / gcdValue);
  }

  /* Set constructor with default values set for 1/2 */
  void setRationalNumber(int numerator = 1, int denominator = 2)
  {
    this->numerator = numerator;
    this->denominator = denominator;
  }

  int gcd(int num1, int num2)
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
  int getNumerator()
  {
    return numerator;
  };
  /** Return the denominator */
  int getDenominator()
  {
    return denominator;
  };

  /** Returns a string representation of a
Rational number in the form a/b , where a is the
numerator and b is the denominator */
  string toRationalString() const
  {
    ostringstream output;
    output << numerator << "/" << denominator;
    return output.str();
  }

  /** Returns the Rational number as a double */
  double toDouble() const
  {
    return static_cast<double>(numerator) / denominator;
  }

  // Overloaded Operator function for + - * / == !=

  /** Adds two RationalNumber numbers.
  The result should be stored in reduced form */
  RationalNumber operator+(RationalNumber r)
  {
    int numerator = this->numerator * r.denominator + r.numerator * this->denominator;
    int denominator = this->denominator * r.denominator;
    return RationalNumber(numerator, denominator);
  }

  /** Subtracts two RationalNumber numbers
  Store the result in reduced form */
  RationalNumber operator-(RationalNumber r)
  {
    int numerator = this->numerator * r.denominator - r.numerator * this->denominator;
    int denominator = this->denominator * r.denominator;
    return RationalNumber(numerator, denominator);
  }
  /** Multiplies two RationalNumber numbers
  Store the result in reduced form */
  RationalNumber operator*(RationalNumber r)
  {
    int numerator = this->numerator * r.numerator;
    int denominator = this->denominator * r.denominator;
    return RationalNumber(numerator, denominator);
  }
  /** Divides two RationalNumber numbers
  The result should be stored in reduced form */
  RationalNumber operator/(RationalNumber r)
  {
    int numerator = this->numerator * r.denominator;
    int denominator = this->denominator * r.numerator;
    return RationalNumber(numerator, denominator);
  }

  // Equality Operators
  bool operator==(RationalNumber r)
  {
    return this->numerator == r.numerator && this->denominator == r.denominator;
  }
  bool operator!=(RationalNumber r)
  {
    return this->numerator != r.numerator || this->denominator != r.denominator;
  }

  // Relational Operators
  bool operator<(const RationalNumber &r) const
  {
    return this->toDouble() < r.toDouble();
  }
  bool operator>(const RationalNumber &r) const
  {
    return this->toDouble() > r.toDouble();
  }
  bool operator<=(const RationalNumber &r) const
  {
    return this->toDouble() < r.toDouble();
  }
  bool operator>=(const RationalNumber &r) const
  {
    return this->toDouble() > r.toDouble();
  }

private:
  int numerator;
  int denominator;
};

int main()
{
  int n1, d1, n2, d2; // denominators and numerators for 2 rational fractions

  string red = "\x1b[21;1;31m";
  string white = "\x1b[24;37m";

  cout << "\x1b[1;36mPlease input a rational fraction!" << endl;
  cout << "\x1b[1;35mNumerator:\t"
       << " \x1b[1;33m";
  cin >> n1;
  cout << "\x1b[1;35mDenominator:\t"
       << " \x1b[1;33m";
  cin >> d1;
  RationalNumber r = RationalNumber(n1, d1);
  cout << "\x1b[1;36]" << n1 << "/" << d1 << "\t=\t";
  cout << r.toRationalString() << "\t= " << r.toDouble() << endl
       << endl;

  cout << "\x1b[1;36mPlease input another rational fraction, for operations!" << endl;
  cout << "\x1b[1;35mNumerator:\t"
       << " \x1b[1;33m";
  cin >> n2;
  cout << "\x1b[1;35mDenominator:\t"
       << " \x1b[1;33m";
  cin >> d2;
  RationalNumber r2 = RationalNumber(n2, d2);
  cout << "\x1b[1;36]" << n2 << "/" << d2 << "\t=\t";
  cout << r2.toRationalString() << "\t= " << r2.toDouble() << endl
       << endl;

  RationalNumber rAdd = r + r2;
  cout << red << "Add\x1b[24;32m\t\t +\t\x1b" << white << rAdd.toRationalString() << "\t= " << rAdd.toDouble() << endl;

  RationalNumber rSubtract = r - r2;
  cout << red << "Subtract\x1b[24;32m\t -\t" << white << rSubtract.toRationalString() << "\t= " << rSubtract.toDouble() << endl;

  RationalNumber rMultiply = r * r2;
  cout << red << "Multiply\x1b[24;32m\t *\t" << white << rMultiply.toRationalString() << "\t= " << rMultiply.toDouble() << endl;

  RationalNumber rDivide = r / r2;
  cout << red << "Divide\x1b[24;32m\t\t /\t" << white << rDivide.toRationalString() << "\t= " << rDivide.toDouble() << endl
       << endl;

  cout << red << "Equality\x1b[24;32m\t ==\t" << white << rAdd.toRationalString() << "\t== "
       << rAdd.toRationalString() << "\t "
       << (rAdd == rAdd ? "TRUE" : "FALSE")
       << endl;

  cout << red << "Inequality\x1b[24;32m\t !=\t" << white << rAdd.toRationalString() << "\t!= "
       << rSubtract.toRationalString() << "\t "
       << (rAdd != rSubtract ? "TRUE" : "FALSE")
       << endl
       << endl;

  cout << red << "Greater than\x1b[24;32m\t >\t" << white << rAdd.toRationalString() << "\t> "
       << rSubtract.toRationalString() << "\t "
       << (rAdd > rSubtract ? "TRUE" : "FALSE")
       << endl;

  cout << red << "Less than\x1b[24;32m\t <\t" << white << rAdd.toRationalString() << "\t< "
       << rSubtract.toRationalString() << "\t "
       << (rAdd < rSubtract ? "TRUE" : "FALSE")
       << endl;
  
    cout << red << "G or Equal\x1b[24;32m\t >=\t" << white << rAdd.toRationalString() << "\t>= "
       << rSubtract.toRationalString() << "\t "
       << (rAdd >= rSubtract ? "TRUE" : "FALSE")
       << endl;

  cout << red << "L or Equal\x1b[24;32m\t <=\t" << white << rAdd.toRationalString() << "\t<= "
       << rSubtract.toRationalString() << "\t "
       << (rAdd <= rSubtract ? "TRUE" : "FALSE")
       << endl
       << endl;

  cout << "\x1b[0m" << endl;
}

/* SAMPLE OUTPUT
Please input a rational fraction!
Numerator:       2
Denominator:     4
2/4     =       1/2     = 0.5

Please input another rational fraction, for operations!
Numerator:       3
Denominator:     9
3/9     =       1/3     = 0.333333

Add              +      5/6     = 0.833333
Subtract         -      1/6     = 0.166667
Multiply         *      1/6     = 0.166667
Divide           /      3/2     = 1.5

Equality         ==     5/6     == 5/6   TRUE
Inequality       !=     5/6     != 1/6   TRUE

Greater than     >      5/6     != 1/6   TRUE
Less than        <      5/6     != 1/6   FALSE
G or Equal       >=     5/6     != 1/6   TRUE
L or Equal       <=     5/6     != 1/6   FALSE */