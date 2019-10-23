#include "io.c"

#define N 2 // 60
#define M 3 // 85

int main() {
  int *A, *B, *m1, *m2;

  A = readArray(N);
  B = readArray(M);
  m1 = &A[0];
  m2 = &B[0];
  for (int i = 1; i < N; i++)
    if (A[i] > *m1)
      m1 = &A[i];
  for (int i = 1; i <= M; i++)
    if (B[i] > *m2)
      m2 = &B[i];
  
  int tmp = *m1;
  *m1 = *m2;
  *m2 = tmp;

  printArray(A, N);
  printArray(B, M);
  free(A);
  free(B);
  free(m1);
  free(m2);
}