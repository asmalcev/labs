#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main () {
  double x, a, s;
  int n = 1;
  scanf ("%lf", &x);
  if (fabs(x) >= 1)
    return 0;
  a = -x / 2;
  s = 1 + a;
 while (fabs(a) > 1e-5) {
    n++;
    a *= 1;
    s += a;
  }
  printf ("s=%.5lf\n y(%lf)=%.5lf\n", s, x, ln(x + a));
} 