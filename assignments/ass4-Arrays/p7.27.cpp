#include <iostream>
#include <array>
#include <iomanip>
using namespace std;

/**
7.27 (The Sieve of Eratosthenes)

A prime integer is any integer that’s evenly divisible only by itself and 1
The Sieve of Eratosthenes is a method of finding prime numbers

It operates as follows:

A.  Create an array with all elements initialized to 1 (true)
    Array elements with prime subscripts will remain 1
    All other array elements will eventually be set to zero
    You’ll ignore elements 0 and 1 in this exercise

B.  Starting with array subscript 2,
    every time an array element is found whose value is 1,
    loop through the remainder of the array
    and set to zero every element whose subscript
    is a multiple of the subscript for the element with value 1

    For array subscript 2, all elements beyond 2 in the array that are multiples of 2
    will be set to zero (subscripts 4, 6, 8, 10, etc.); for array subscript 3,
    all elements beyond 3 in the array that are multiples of 3 will be set to zero
    (subscripts 6, 9, 12, 15, etc.); and so on.

When this process is complete,
the array elements that are still set to one
indicate that the subscript is a prime number
These can then be printed
Write a program that uses an array of 1000 elements to determine and
print the prime numbers between 2 and 999
Ignore element 0 of the array */
int main()
{
  const int SIZE = 1000;
  int arr[SIZE];
  int subscript{1};

  for (int i{0}; i < SIZE; i++) // initialize all elements to 1
    arr[i] = 1;

  // if element is divisible by subscript set to 0, as it is not a prime
  while (subscript++ <= (SIZE / 2))
    for (int i{0}; i < SIZE; i++)
      if (i % subscript == 0 && i != subscript) // remember primes are divisible by themselves
        arr[i] = 0;

  int col{1};                   // set columns for table display
  for (int i{2}; i < SIZE; i++) // don't print 0 or 1
    if (arr[i] == 1)            // print all numbers still set to 1 (primes)
      cout << "\x1b[0;1;38;5;" << i << ";7m " << setw(4) << left
           << i << (col++ % 12 == 0 ? "\n" : "");
  cout << "\x1b[0m \n\n";
}
