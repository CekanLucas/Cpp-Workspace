#include <iostream>
#include <random>
#include <ctime>
#include <string>
using namespace std;

/**
6.34 (Guess-the-Number Game)
Write a program that plays the game of “guess the number” as follows:
  Your program chooses the number to be guessed
  by selecting an integer at random in the range 1 to 1000

The program then displays the following:

  I have a number between 1 and 1000.
  Can you guess my number?
  Please type your first guess.

The player then types a first guess.
The program responds with one of the following:

1.  Excellent! You guessed the number!
    Would you like to play again (y or n)?
2.  Too low. Try again.
3.  Too high. Try again.

If the player’s guess is incorrect, your program should loop until
the player finally gets the number right.
Your program should keep telling the player Too high or Too low to help the player
“zero in” on the correct answer */

int main()
{
  unsigned int seed{static_cast<unsigned int>(time(0))};
  default_random_engine engine{seed};
  uniform_int_distribution<unsigned int> randomInt{1, 1000};
  unsigned int randomNum{randomInt(engine)};
  randomNum = randomInt(engine); // for some reason number more random if you reassign again

  cout << "\x1b[0;36mWelcome to guess a number!" << endl
       << "Pick a number from 1 to 1000\n\x1b[1;33m";

  while (true)
  {
    int userNum;
    cin >> userNum;

    if (userNum == randomNum)
    {
      cout << "\x1b[1;32mExcellent! You guessed the number!" << endl
           << "Would you like to play again(y or n)?\t\x1b[1;33m";

      string playAgain;
      cin >> playAgain;
      if (playAgain == "y")
      {
        randomNum = randomInt(engine);
        cout << "\x1b[0;36m\nWelcome again to guess a number!" << endl
             << "Pick a number from 1 to 1000\n\x1b[1;33m";
      }
      else
        break;
    }
    else
      cout << "\x1b[0;31m" << (userNum > randomNum ? "Too high.\tTry again\n" : "Too low.\tTry again\n") << "\x1b[1;33m";
  }

  cout << "\n\x1b[24;101mPlay again, anytime, BYE!\n\x1b[0m" << endl;
}