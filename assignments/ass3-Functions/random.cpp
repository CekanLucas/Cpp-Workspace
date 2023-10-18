// Using a C++11 random-number generation engine and distribution
// to roll a six-sided die

#include<iostream>
#include <random> // contains C++11 random number generation features
#include<iomanip>
#include <ctime>
using namespace std;


int main() {
  // use default random-number generation engine to
  // produce uniformly distributed pseudorandom int values from 1 to 6
  default_random_engine engine{static_cast<unsigned int>(time(0))};
  uniform_int_distribution<unsigned int> randomInt{1, 6};

  for (unsigned int counter{1}; counter <= 10; ++counter) {
    cout << setw(10) << randomInt(engine); 

    if(counter % 5 == 0) {
      cout << endl;
    } 
  }
}