#include <stdio.h>

// int sum(int num1, int num2); // function declaration

// // Take user input
// int main()
// {

//   int a, b, c;

//   printf("\x1b[35mEnter the value of a\x1b[1;33m\t");
//   scanf("%d", &a);

//   printf("\n\x1b[35mEnter the value of b\x1b[1;33m\t");
//   scanf("%d", &b);

//   c = sum(a, b);

//   printf("\n\x1b[34mAddition\t=\t\x1b[1;33m%d\n\n\x1b[0m", c);

//   return 0;
// }

// int sum(int num1, int num2)
// {
//   return num1 + num2;
// }

#include <stdio.h>

int main() {
  int c;
  c = getchar();
  while (c != EOF) {
    putchar(c);
    c = getchar();
  }
  return 0;
}