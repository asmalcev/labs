#include "io.c"

#define N 5
#define M 7

double* firstMax(double* arr, int length);
double* lastMax(double* arr, int length);

int main() {
  double *A, *B, *m1, *m2;

  A = readArray(N);
  B = readArray(M);
  m1 = firstMax(A, N);
  m2 = lastMax(B, M);
  double tmp = *m1;
  *m1 = *m2;
  *m2 = tmp;

  printArray(A, N);
  printArray(B, M);
  free(A);
  free(B);
}

double* firstMax(double* arr, int length) {
  double* m = arr;
  for (int i = 1; i < N; i++)
    if (arr[i] > *m)
      m = &arr[i];
  return m;
}
double* lastMax(double* arr, int length) {
  double* m = arr;
  for (int i = 1; i <= N; i++)
    if (arr[i] > *m)
      m = &arr[i];
  return m;
}