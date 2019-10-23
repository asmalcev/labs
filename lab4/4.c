#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);
  int a[n][n];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      scanf("%d", &a[i][j]);
  int isSym = 1;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (a[i][j] != a[j][i])
        isSym = 0;
  printf("matrix %s sym\n", isSym ? "is" : "is't");
}