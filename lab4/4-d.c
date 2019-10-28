#include <stdio.h>
#include <stdlib.h>

int main() {
  short n;
  scanf("%hd", &n);
  double *a = (double*)malloc(n*n * sizeof(double));
  for (short i = 0; i < n; i++)
    for (short j = 0; j < n; j++)
      scanf("%le", &a[i*n + j]);
  char isSym = 1;
  for (short i = 0; isSym && i < n; i++)
    for (short j = 0; isSym && j < n; j++)
      isSym = a[i*n + j] == a[j*n + i] ? 1 : 0;
  printf("matrix %s sym\n", isSym ? "is" : "isn't");
}