#include <iostream>
#include <string>
/**
5.15 (Drawing Patterns with Nested for Loops)
Write an program that uses `for` statements to print the following patterns separately,
one below the other.

Use `for` loops to generate the patterns.
All asterisks ( * ) should be printed by a single statement of the form `cout << '*';`
(this causes the asterisks to print side by side).

Hint: The last two patterns require that each line begin with an appropriate number of blank
spaces

  \code{.unparsed}
  A.            B.            C.            D.
  *             **********    **********             *
  **            *********      *********            **
  ***           ********        ********           ***
  ****          *******          *******          ****
  *****         ******            ******         *****
  ******        *****              *****        ******
  *******       ****                ****       *******
  ********      ***                  ***      ********
  *********     **                    **     *********
  **********    *                      *    **********
  /endcode
**/
int main()
{
  using namespace std;

  const int ROWS{10};
  const int WIDTH{10};
  char pattern{'A'};
  int color{2};

  for (int i = 0; i < 4; i++)
  {
    cout << ("\x1b[3" + to_string(color++) + "m(" + pattern++ + ")");

    for (int j = 3; j < WIDTH; j++)
      cout << ' ';
    
    cout << "\t";
  }
  cout << endl << endl;

  for (int i = 1; i < ROWS; i++)
  {
    color = 2; // reset color

    cout << "\x1b[3" + to_string(color++) + "m";
    for (int j = 1; j < WIDTH; j++) // A.
      cout << (j <= i ? '*' : ' ');
    cout << "\x1b[3" + to_string(color++) + "m\t";

    for (int j = 1; j < WIDTH; j++) // B.
      cout << (WIDTH - j >= i ? '*' : ' ');
    cout << "\x1b[3" + to_string(color++) + "m\t";

    for (int j = 1; j < WIDTH; j++) // C.
      cout << (j >= i ? '*' : ' ');
    cout << "\x1b[3" + to_string(color++) + "m\t";

    for (int j = 1; j < WIDTH; j++) // D.
      cout << (WIDTH - j <= i ? '*' : ' ');
    cout << "\x1b[3" + to_string(color++) + "m\t" << endl;
  }
  cout << "\x1b[0m\n\n";
}