#include <stdio.h>

int main() {
  double P = 0, a;
  for (int i = 1; i <= 10; i++) {
    a = 0;
    for (int j = 1; j <= 20; j++)
      a += 1. / (i + j*j);
    P *= a;
  }
  printf("%lf\n", P);
}