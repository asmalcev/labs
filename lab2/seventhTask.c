#include <stdio.h>
#include <math.h> 

int main () {
  double x, a, s;
  int n = 0;
  scanf("%lf", &x);
  a = 0.5;
  s = 0.5 + a;
  while (fabs(a) > 1e-5) {
    n++;
    a *= -pow(x, 2) / n;
    s += a;
  }
  printf("s=%lf\n cos(%lf)=%lf\n", s, x, cos(x));
}