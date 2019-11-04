#include "io.c"

#define N 5
#define M 7

int main() {
  double *A, *B, *m1, *m2;

  A = readArray(N);
  B = readArray(M);
  m1 = A;
  m2 = B;
  for (int i = 1; i < N; i++)
    if (A[i] > *m1)
      m1 = &A[i];
  for (int i = 1; i <= M; i++)
    if (B[i] > *m2)
      m2 = &B[i];
  
  double tmp = *m1;
  *m1 = *m2;
  *m2 = tmp;

  printArray(A, N);
  printArray(B, M);
  free(A);
  free(B);
}