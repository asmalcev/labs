#include <stdio.h>
#include <math.h>

int main () {
  double x, a = 1, s = 0;
  int n = 0;
  scanf("%lf", &x);
  while (fabs(a) > 1e-5) {
    n++;
    s += a;
    a *= -pow(x, 2) / (2*n - 1) / (2*n);
  }
  printf("s=%lf\ncos(%lf)=%lf\n", s, x, cos(x));
}