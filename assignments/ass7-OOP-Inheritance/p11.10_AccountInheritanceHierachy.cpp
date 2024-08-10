#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
using namespace std;

/** 11.10 ( Account Inheritance Hierarchy)
Create an inheritance hierarchy that a bank might use
to represent customers’ bank accounts

All customers at this bank can deposit (i.e., credit)
money into their accounts and withdraw (i.e., debit)
money from their accounts

More specific types of accounts also exist
Savings accounts, for instance, earn interest on the money they hold

Checking accounts, on the other hand, charge a fee per
transaction (i.e., credit or debit)

Create an inheritance hierarchy containing base-class `Account`
and derived classes `SavingsAccount` and `CheckingAccount` that
inherit from class Account

Base-class `Account` should include
one data member of type `double` to represent the account balance

The class should provide a constructor that receives
an initial balance and uses it to initialize the data member

The constructor should validate the initial balance to ensure that it’s
greater than or equal to 0.0

If not, the balance should be set to
0.0 and the constructor should display an error message,
indicating that the initial balance was invalid

The class should provide three member functions

- Member function `credit` should add an amount to the current balance
- Member function `debit` should withdraw money from the Account and ensure that
  the debit amount does not exceed the Account ’s balance
    If it does, the balance should be left unchanged and the function
    should print the message "Debit amount exceeded account balance."
- Member function `getBalance` should return the current balance

Derived-class `SavingsAccount` should inherit the functionality of an Account,
but also include a data member of type double
indicating the interest rate (percentage) assigned to the Account

SavingsAccount’s constructor should receive the initial balance,
as well as an initial value for the SavingsAccount ’s interest rate

SavingsAccount should provide a public member
function `calculateInterest` that returns a `double` indicating the
amount of interest earned by an account

Member function `calculateInterest` should determine this amount by multiplying
the interest rate by the account balance

NOTE: SavingsAccount should inherit member functions credit
and debit as is without redefining them

Derived-class `CheckingAccount` should inherit from base-class

Account and include an additional data member of type double
that represents the fee charged per transaction

CheckingAccount ’s constructor should receive the initial balance,
as well as a parameter indicating a fee amount

Class `CheckingAccount` should redefine member functions
`credit` and `debit` so that they subtract the fee from the account balance
whenever either transaction is performed successfully

CheckingAccount ’s versions of these functions should invoke the
base-class Account version to perform the updates to an account balance

CheckingAccount’s debit function should
charge a fee only if money is actually withdrawn
(i.e., the debit amount does not exceed the account balance)

[Hint: Define Account ’s debit function so that it returns a bool indicating
whether money was withdrawn
Then use the return value to determine whether a fee should be charged.]

After defining the classes in this hierarchy,
write a program that creates objects of each class and tests their member functions

Add interest to the `SavingsAccount` object by first invoking its
`calculateInterest` function, then passing the returned interest
amount to the object’s credit function */

class Account
{
public:
  Account(double initialBalance)
  {
    cout << "\x1b[32m" << endl
         << setw(70) << left << "New account was initialised with initial balance of"
         << "\x1b[33;1;7m  $"
         << fixed << setprecision(2) << setw(10) << right << initialBalance << " \x1b[0m" << endl;
    if (initialBalance >= 0)
    {
      this->balance = initialBalance;
    }
    else
      cout << "\x1b[1;31;7m ERROR \x1b[22m" << setw(80 - 3) << left
           << "New account cannot be initialised with initial balance less than $0 " << endl;
    cout << "\x1b[0m";
  }

  double getBalance()
  {
    return balance;
  }

  void credit(double amount)
  {
    balance += amount;

    cout << "\x1b[34m" << setw(70) << left
         << "Amount deposited/credited"
         << "\x1b[33;21;7m +$"
         << fixed << setprecision(2) << setw(10) << right << amount << " " << endl
         << "\x1b[0;34m" << setw(70) << left << "New balance"
         << "\x1b[33;1;7m  $"
         << setw(10) << right << balance << " \x1b[0m" << endl;
  }

  void debit(double amount)
  {
    if (amount <= balance)
    {
      balance -= amount;

      cout << "\x1b[34m" << setw(70) << left
           << "Amount withdrawn/debited"
           << "\x1b[33;21;7m -$"
           << fixed << setprecision(2) << setw(10) << right << amount << " " << endl
           << "\x1b[0;34m" << setw(70) << left << "New balance"
           << "\x1b[33;1;7m  $"
           << setw(10) << right << balance << " \x1b[0m" << endl;
    }
    else
      cout << "\x1b[1;31;7m ERROR \x1b[22m" << setw(80 - 3) << left
           << "Debit amount exceeded account balance";
  }

protected:
  double balance;
};

class SavingsAccount
    : Account
{
public:
  SavingsAccount(double initialBalance, double initialInterestRate)
      : Account(initialBalance)
  {
    cout << "\x1b[1;95;21m"
         << setw(74) << left << "New savings account initialized\x1b[0m"
         << "\x1b[33;1;7m"
         << setw(10) << right << "              "
         << "\x1b[0m" << endl;

    this->interestRate = initialInterestRate;

    cout << "\x1b[35m"
         << setw(70) << left << "Saving Account interest rate is"
         << "\x1b[33;1;7m  %"
         << fixed << setprecision(2) << setw(10) << right << initialInterestRate << " \x1b[0m" << endl;
  }

  double calculateInterest()
  {
    return (1 / interestRate) * balance;
  }

  using Account::credit;
  using Account::debit;

private:
  double interestRate; // percentage
};

class CheckingAccount
    : Account
{
public:
  CheckingAccount(double initialBalance, double feePerTransaction)
      : Account(initialBalance)
  {
    this->fee = feePerTransaction;

    cout
        << "\x1b[0m\x1b[1;95;21m"
        << setw(74) << left << "New checking account initialized\x1b[0m"
        << "\x1b[33;1;7m"
        << setw(10) << right << "              "
        << "\x1b[0m" << endl
        << "\x1b[95m" << setw(70) << left
        << "Checking Account has fee per transaction"
        << "\x1b[1;33;7m  $"
        << fixed << setprecision(2) << setw(10) << right << fee << " "
        << "\x1b[0m" << endl;
  }

  void credit(double amount)
  {
    Account::credit(amount);
    balance -= fee;

    cout << "\x1b[34m" << setw(70) << left
         << "Transaction fee charged"
         << "\x1b[33;21;7m -$"
         << fixed << setprecision(2) << setw(10) << right << fee << " " << endl
         << "\x1b[0;34m" << setw(70) << left << "New balance"
         << "\x1b[33;1;7m  $"
         << setw(10) << right << balance << " \x1b[0m" << endl;
  }

  void debit(double amount)
  {
    if (amount + fee <= balance)
    {
      Account::debit(amount);
      balance -= fee;

      cout << "\x1b[34m" << setw(70) << left
           << "Transaction fee charged"
           << "\x1b[33;21;7m -$"
           << fixed << setprecision(2) << setw(10) << right << fee << " " << endl
           << "\x1b[0;34m" << setw(70) << left << "New balance"
           << "\x1b[33;1;7m  $"
           << setw(10) << right << balance << " \x1b[0m" << endl;
    }
    else
      cout << "\x1b[1;31;7m ERROR \x1b[22m" << setw(80 - 3) << left
           << "Debit amount exceeded account balance" << endl;
  }

private:
  double fee; // fee charged per transaction
};

int main()
{
  Account account1 = Account(-1);
  Account account2 = Account(12.99);
  account2.credit(100.0);
  account2.debit(50.5);
  SavingsAccount account3 = SavingsAccount(49.99, 5.99);

  cout << "\x1b[36m" << setw(70) << left
       << "Interest calculated for saving account"
       << "\x1b[33;21;7m  $"
       << fixed << setprecision(2) << setw(10) << right << account3.calculateInterest() << " " << endl
       << "\x1b[0m\x1b[1;96;21m"
       << setw(74) << left << "Crediting interest to balance\x1b[0m"
       << "\x1b[33;1;7m"
       << setw(10) << right << "              "
       << "\x1b[0m" << endl;

  account3.credit(account3.calculateInterest());

  CheckingAccount account4 = CheckingAccount(121.15, 2.55);
  account4.credit(50);
  account4.debit(20);
  cout << "\x1b[0m" << endl
       << endl;
}