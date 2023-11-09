#include <iostream>
#include <string>
#include <iomanip>
#include "Rational.cpp"
using namespace std;

int main()
{
  int n1, d1, n2, d2; // denominators and numerators for 2 rational fractions

  string red = "\x1b[21;1;31m";
  string white = "\x1b[24;37m";

  cout << "\x1b[1;36mPlease input a rational fraction!" << endl;
  cout << "\x1b[1;35mNumerator:\t" << " \x1b[1;33m";
  cin >> n1; 
  cout << "\x1b[1;35mDenominator:\t" << " \x1b[1;33m";
  cin >> d1;
  Rational r = Rational(n1, d1);
  cout << "\x1b[1;36]" << n1 << "/" << d1 << "\t=\t";
  cout << r.toRationalString() << "\t= " << r.toDouble() << endl << endl;

  cout << "\x1b[1;36mPlease input another rational fraction, for operations!" << endl;
  cout << "\x1b[1;35mNumerator:\t" << " \x1b[1;33m";
  cin >> n2; 
  cout << "\x1b[1;35mDenominator:\t" << " \x1b[1;33m";
  cin >> d2;
  Rational r2 = Rational(n2, d2);
  cout << "\x1b[1;36]" << n2 << "/" << d2 << "\t=\t";
  cout << r2.toRationalString() << "\t= " << r2.toDouble() << endl << endl;
  
  Rational rAdd = r.add(r2);
  cout << red << "Add:\t\t\x1b" << white << rAdd.toRationalString() << "\t= " << rAdd.toDouble() << endl;

  Rational rSubtract = r.subtract(r2);
  cout << red << "Subtract:\t" << white << rSubtract.toRationalString() << "\t= " << rSubtract.toDouble() << endl;

  Rational rMultiply = r.multiply(r2);
  cout << red << "Multiply:\t" << white << rMultiply.toRationalString() << "\t= " << rMultiply.toDouble() << endl;

  Rational rDivide = r.divide(r2);
  cout << red << "Divide:\t\t" << white << rDivide.toRationalString() << "\t= " << rDivide.toDouble() << endl;

  cout << "\x1b[0m" << endl;
}
