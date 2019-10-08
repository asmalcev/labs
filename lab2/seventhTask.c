#include <stdio.h>
#include <math.h>

int main () {
  double x, a = 1, s = 0, x2, n2;
  int n = 0;
  scanf("%lf", &x);
  x2 = x * x;
  while (fabs(a) > 1e-5) {
    n++;
    s += a;
    n2 = 2*n;
    a *= -x2 / ((n2 - 1) * n2);
  }
  printf("s=%lf\ncos(%lf)=%lf\n", s, x, cos(x));
}