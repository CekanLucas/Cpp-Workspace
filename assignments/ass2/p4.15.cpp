#include <iostream>
#include <iomanip>

/** 4.15 (Sales-Commission Calculator)
A large company pays its salespeople on a commission basis.
The salespeople each receive $200 per week plus 9% of their gross sales for that week.

For example, a salesperson who sells $5000 worth of chemicals in a week receives $200 plus 9% of $5000, or a total of $650.

Develop a C++ program that uses a while statement to input each salesperson’s gross sales for last week and calculates and displays that salesperson’s earnings. Process one salesperson’s figures at a time.

EXAMPLE OUTPUT
  Enter sales in dollars (-1 to end): 5000.00
  Salary is: $650.00

  Enter sales in dollars (-1 to end): 6000.00
  Salary is: $740.00

  Enter sales in dollars (-1 to end): 7000.00
  Salary is: $830.00

  Enter sales in dollars (-1 to end): -1

*/
int main()
{
  using namespace std;
  const float COMMISSION{0.09};
  const int SALARY{200};
  const string PROMPT{"\x1b[0;36mEnter sales in dollars (-1 to end):\t\x1b[1;33m$"};
  const string RESULT_PROMPT{"\x1b[1;32mSalary is:\t\x1b[1;102m$"};
  auto sales{0};

  while (true)
  {
    cout << PROMPT;
    cin >> sales;

    if(sales == -1)
      break;

    cout << RESULT_PROMPT << setprecision(2) << fixed << SALARY + sales * COMMISSION << endl << endl;
  }

  cout << "\x1b[24;101m\n\tProcess complete! Have a nice day!\t\n\n\x1b[0m" << endl;
}
