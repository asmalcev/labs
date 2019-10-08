#include <stdio.h>

int main() {
  double P, a;
  for (int i = 1; i <= 2; i++) {
    a = 0;
    for (int j = 1; j <= 2; j++)
      a += 1. / (i + j*j);
    P += a;
  }
  printf("%lf\n", P);
}