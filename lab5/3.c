#include "io.c"
#include <math.h>

#define N 30

double Integral(double a, double b, double (*func) (double));
double f1(double x);
double f2(double x);

int main() {
  if (N % 3 != 0)
    printf("N %% 3 != 0\n");
  else
    printf("%lf %lf\n", Integral(-1, 4, f1), Integral(0.5, 3.5, f2));
}

double Integral(double a, double b, double (*func) (double)) {
  double s = 0, dx = (b - a) / N;
  int i = 0;
  for (double x = a; x < b; x += dx, i++)
    s += (i == N ? 1 : i % 3 == 0 ? 2 : 3)* func(x);

  return s * 3*(b - a) / (8*N);
}

double f1(double x) {
  return 2*x*(x*x + 1);
}

double f2(double x) {
  return exp(2*x) / (2*x);
}