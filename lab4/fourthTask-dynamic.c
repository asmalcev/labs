#include <stdio.h>
#include <stdlib.h>

int main() {
  int n;
  scanf("%d", &n);
  int *a = (int*)malloc(n*n * sizeof(int));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      scanf("%d", &a[i*n + j]);
  int isSym = 1;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (a[i*n + j] != a[j*n + i])
        isSym = 0;
  printf("matrix %s sym\n", isSym ? "is" : "is't");
  free(a);
}