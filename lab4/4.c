#include <stdio.h>

int main() {
  short n;
  scanf("%hd", &n);
  double a[n][n];
  for (short i = 0; i < n; i++)
    for (short j = 0; j < n; j++)
      scanf("%le", &a[i][j]);
  char isSym = 1;
  for (short i = 0; isSym && i < n; i++)
    for (short j = 0; isSym && j < n; j++)
      isSym = a[i][j] == a[j][i] ? 1 : 0;
  printf("matrix %s sym\n", isSym ? "is" : "isn't");
}