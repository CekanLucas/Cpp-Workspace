#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
/**
5.17 (Calculating Sales)
An online retailer sells five products
whose retail prices are as follows:
  Product 1, $2.98;
  product 2, $4.50;
  product 3, $9.98;
  product 4, $4.49;
  product 5, $6.87;

Write an application that reads a series of pairs of numbers as follows:
A. product number
B. quantity sold

Your program should use a switch statement to determine the
retail price for each product.

It should calculate and display the total retail value of all products sold.

Use a sentinel-controlled
loop to determine when the program should stop looping and
display the final results */
int main()
{

  double total1{0}, total2{0}, total3{0}, total4{0}, total5{0};
  int productNumber{1};
  int quantitySold{0};
  float price{0};

  cout << "\x1b[1;34mPlease enter product number followed by quantity sold for each product" << endl
       << "\x1b[22;31mInput EOF to exit and calculate total so far \x1b[7m <CNTRL-D> on UNIX/LINUX " << endl
       << endl
       << "\x1b[0;1;33m";

  while (true)
  {
    cout << "\x1b[1;33m";
    cin >> productNumber >> quantitySold;

    if (cin.eof())
    {
      cout << "\x1b[91mEOF exit condition commenced ";
      break;
    }

    switch (productNumber)
    {
    case 1:
      price = 2.98;
      total1 = price * quantitySold;
      break;
    case 2:
      price = 4.50;
      total2 = price * quantitySold;
      break;
    case 3:
      price = 9.98;
      total3 = price * quantitySold;
      break;
    case 4:
      price = 4.49;
      total4 = price * quantitySold;
      break;
    case 5:
      price = 6.87;
      total5 = price * quantitySold;
      break;
    default:
      cout << "\x1b[1;31mProduct does not exist!";
      break;
    }

    cout << "\x1b[0;35mTotal retail value for product " << to_string(productNumber++) << " :\t\x1b[0;31m$"
         << price << setprecision(2) << fixed << " x " << to_string(quantitySold) << " =\t\x1b[1;45m $"
         << price * quantitySold << setprecision(2) << fixed << " \x1b[0m" << endl;
  }

  double total = total1 + total2 + total3 + total4 + total5;
  cout << "\n\n\x1b[0;1;36mTotal retail value for all products :\t\t\t\x1b[1;42m $"
       << total << setprecision(2) << fixed << " \x1b[0m" << endl
       << endl;
}