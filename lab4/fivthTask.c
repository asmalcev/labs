#include <stdio.h>
#include <stdlib.h>

int main() {
  int m = 3, n = 3, p = 3;
  // scanf("%d %d %d", &m, &n, &p);
  int*** cont = (int***) malloc(p * sizeof(int**));
  for (int i = 0; i < p; i++) {
    cont[i] = (int**) malloc(n * sizeof(int*));
    for (int j = 0; j < n; j++)
      cont[i][j] = (int*) malloc(m * sizeof(int));
  }
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      for (int k = 0; k < p; k++)
        scanf("%d", &cont[i][j][k]);

  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < p; k++)
        printf("%d ", cont[i][j][k]);
      printf("\n");
    }
  free(cont);
}