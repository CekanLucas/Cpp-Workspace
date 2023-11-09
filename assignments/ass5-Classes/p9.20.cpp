#include <iostream>
#include <iomanip>
#include "SavingsAccount.cpp"

using namespace std;

/**
9.20 ( `SavingsAccount` Class)
Create a `SavingsAccount` class

Write a driver program to test class `SavingsAccount`

Instantiate two different objects of class SavingsAccount , saver1 and saver2 , with balances of
$2000.00 and $3000.00, respectively. Set the
`annualInterestRate` to 3 percent

Then calculate the monthly interest and print the new balances for each of the savers.
Then set the `annualInterestRate` to 4 percent,
calculate the next month’s interest and print the new balances for each of the savers */
int main() {

  string green = "\x1b[24;22;32m";
  string blue = "\x1b[21;1;36m";
  string white = "\x1b[24;37m";
  string yellow = "\x1b[1;33m";

  SavingsAccount saver1 = SavingsAccount(2000.00, 0.03);
  cout << blue << "New saving account opened;" << green << " account 1!" << endl;
  cout << white << "Balance:\t\t$" << saver1.getSavingsBalance() << fixed << setprecision(2) << endl;
  cout << white << "Annual Interest Rate:\t%" << (saver1.getAnnualInterestRate() * 100) << endl;
  cout << endl;

  SavingsAccount saver2 = SavingsAccount(3000.00, 0.03);
  cout << blue << "New saving account opened;" << green << " account 2!" << endl;
  cout << white << "Balance:\t\t$" << saver2.getSavingsBalance() << fixed << setprecision(2) << endl;
  cout << white << "Annual Interest Rate:\t%" << (saver2.getAnnualInterestRate() * 100) << endl;
  cout << endl;

  cout << blue << "New balance after a month" << endl;
  saver1.calculateMonthlyInterest();
  saver2.calculateMonthlyInterest();
  cout << green << "For account 1:\t\t" << yellow << "$" << saver1.getSavingsBalance() << fixed << std::setprecision(2) << endl;
  cout << green << "For account 2:\t\t" << yellow << "$" << saver2.getSavingsBalance() << fixed << setprecision(2) << endl;
  cout << endl;

  cout << blue << "New balance after a month and annual interest of 4%" << endl;
  saver1.modifyInterestRate(0.04);
  saver2.modifyInterestRate(0.04);
  saver1.calculateMonthlyInterest();
  saver2.calculateMonthlyInterest();
  cout << green << "For account 1:\t\t" << yellow << "$" << saver1.getSavingsBalance() << fixed << setprecision(2) << endl;
  cout << green << "For account 2:\t\t" << yellow << "$" << saver2.getSavingsBalance() << fixed << setprecision(2) << endl;
  cout << "\x1b[0m" << endl;
}
