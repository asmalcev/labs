#include "io.c"
#include <math.h>

#define N 5

double sumOfArray(double* arr, int length);
double sumOfSqrsOfArray(double* arr, int length);
double sumOfMultisOfArrays(double* arr, double* arr2, int length);

int main() {
  double *Y, *X;
  double f, n;

  scanf("%lf", &n);
  Y = readArray(N);
  X = readArray(N);

  f = (n * sumOfMultisOfArrays(Y, X, N) - sumOfArray(Y, N) * sumOfArray(X, N)) /
     pow((n*sumOfSqrsOfArray(X, N) - sumOfArray(X, N) * sumOfArray(X, N))
      *(n*sumOfSqrsOfArray(Y, N) - sumOfArray(Y, N) * sumOfArray(Y, N)), 0.5);
  printf("%lf\n", f);
}

double sumOfArray(double* arr, int length) {
  double s = 0;
  for (double* i = arr; i - arr < length; i++)
    s += *i;
  return s;
}

double sumOfSqrsOfArray(double* arr, int length) {
  double s = 0;
  for (double* i = arr; i - arr < length; i++)
    s += (*i) * (*i);
  return s;
}

double sumOfMultisOfArrays(double* arr, double* arr2, int length) {
  double s = 0;
  for (int i = 0; i < length; i++)
    s += arr[i]*arr2[i];
  return s;
}