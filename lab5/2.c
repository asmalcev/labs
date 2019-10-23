#include "io.c"
#include <math.h>

#define N 3 // 30

int sumOfArray(int* arr, int length) {
  int s = 0;
  for (short i = 0; i < length; i++)
    s += arr[i];
  return s;
}

int sumOfSqrsOfArray(int* arr, int length) {
  int s = 0;
  for (short i = 0; i < length; i++)
    s += arr[i]*arr[i];
  return s;
}

int sumOfMultisOfArrays(int* arr, int* arr2, int length) {
  int s = 0;
  for (short i = 0; i < length; i++)
    s += arr[i]*arr2[i];
  return s;
}

int main() {
  int *Y, *X;
  double f, n;

  scanf("%lf", &n);
  Y = readArray(N);
  X = readArray(N);

  f = (n * sumOfMultisOfArrays(Y, X, N) - sumOfArray(Y, N) * sumOfArray(X, N)) /
     pow((n*sumOfSqrsOfArray(X, N) - sumOfArray(X, N) * sumOfArray(X, N))
      *(n*sumOfSqrsOfArray(Y, N) - sumOfArray(Y, N) * sumOfArray(Y, N)), 0.5);
  printf("%lf\n", f);
}