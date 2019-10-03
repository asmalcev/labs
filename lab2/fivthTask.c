#include <stdio.h>

int main() {
  double s = 0, a, b, c;
  while (scanf("%lf %lf %lf", &a, &b, &c) == 3)
    s += a + b + c;
  printf("%lf", s);
}