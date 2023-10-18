// From my quiz

#include <iostream>
#include <random>
#include <ctime> // Include <ctime> for time(0)

using namespace std;

int main()
{
  int c1{3}, c2{2}, c3{6}; // Correct combination
  int g1, g2, g3;          // Initialize guess combination

  // Seed the random number generator
  unsigned int seed{static_cast<unsigned int>(time(0))};
  cout << "\nWith seed:\t" << seed << endl;

  default_random_engine engine{seed};
  uniform_int_distribution<int> randomInt{1, 9};

  int attempts{0}; // Add a counter for attempts

  while (true)
  {
    // Generate guesses
    g1 = randomInt(engine);
    g2 = randomInt(engine);
    g3 = randomInt(engine);

    // Print guesses and increment attempts
    cout << "Attempt " << ++attempts << ": " << g1 << " " << g2 << " " << g3 << endl;

    // Check if the combination is correct
    if (g1 == c1 && g2 == c2 && g3 == c3)
    {
      cout << "Correct combination found in " << attempts << " attempts!" << endl;
      break;
    }
  }
}