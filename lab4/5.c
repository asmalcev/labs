#include <stdio.h>
#include <stdlib.h>

int main() {
  short m, n, p, flag, sFlag;
  scanf("%d %d %d", &m, &n, &p);
  double*** cont = (double***) malloc(p * sizeof(double**));
  for (short i = 0; i < p; i++) {
    cont[i] = (double**) malloc(n * sizeof(double*));
    for (short j = 0; j < n; j++)
      cont[i][j] = (double*) malloc(m * sizeof(double));
  }
  sFlag = 0;
  for (short i = 0; i < m; i++)
    for (short j = 0; j < n; j++)
      for (short k = 0; k < p; k++)
        scanf("%le", &cont[i][j][k]);

  for (short i = 0; i < m; i++) {
    flag = 1;
    for (short j = 0; flag && j < n; j++)
      for (short k = 0; flag && k < p; k++)
        flag = cont[i][j][k] == cont[i][0][0];
    if (flag) {
      sFlag = 1;
      break;
    }
  }
  for (short i = 0; i < n; i++) {
    flag = 1;
    for (short j = 0; flag && j < m; j++)
      for (short k = 0; flag && k < p; k++)
        flag = cont[j][i][k] == cont[0][i][0];
    if (flag) {
      sFlag = 1;
      break;
    }
  }
  for (short i = 0; i < p; i++) {
    flag = 1;
    for (short j = 0; flag && j < n; j++)
      for (short k = 0; flag && k < m; k++)
        flag = cont[j][k][i] == cont[0][0][i];
    if (flag) {
      sFlag = 1;
      break;
    }
  }
  if (sFlag)
    printf("found a layer\n");
  else
    printf("couldn't find a layer\n");
  free(cont);
}