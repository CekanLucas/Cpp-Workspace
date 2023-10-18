#include <iostream>
#include <iomanip>
#include <array>
#include <random> // contains C++ random number generation features
using namespace std;

int main()
{
  int c1{3}, c2{2}, c3{6}; // correct combination

  // random number generation engine and distribution
  unsigned int seed{static_cast<unsigned int>(time(0))};
  cout << "\nWith seed:\t" << seed << endl;

  default_random_engine engine{seed};
  uniform_int_distribution<unsigned int> randomInt{ 1, 9 };

  
  int g1{0}, g2{0}, g3{0}; // guess combination

  while (true)
  {
    // guesses
    g1 = randomInt(engine);
    g2 = randomInt(engine);
    g3 = randomInt(engine);

    if(g1 == c1 && g2 == c2 && g3 == c3)
      break;
  }

  cout << "correct combination found!";
}