#include <stdio.h>

int main() {
  double P;
  for (int i = 1; i <= 10; i++) {
    double a = 0;
    for (int j = 1; j <= 20; j++)
      a += 1 / (i + j*j);
    P += a;
  }
  printf("%g\n", P);
}