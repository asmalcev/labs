#include <stdio.h>
#include <math.h>

int main () {
  double x, a, b, s, k;
  int n = 1;
  scanf ("%lf %lf", &x, &a);
  if (x + a <= 0 || x <= 0) {
    printf("Input error\n");
    return 0;
  }
  s = log(x);
  b = 2*a / (2*x + a);
  k = a*a / ((2*x + a)*(2*x + a));
  while (fabs(b) > 1e-5) {
    s += b / (2*n - 1);
    n++;
    b *= k;
  }
  printf("s=%.5lf\nlog(%lf+%lf)=%.5lf\n", s, x, a, log(x + a));
} 