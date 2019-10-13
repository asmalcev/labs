#include <stdio.h>

int main() {
  double P = 1, a;
  for (char i = 1; i <= 10; i++) {
    a = 0;
    for (char j = 1; j <= 20; j++)
      a += 1. / (i + j*j);
    P *= a;
  }
  printf("%lf\n", P);
}
