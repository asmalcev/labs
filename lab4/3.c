#include <stdio.h>
#include <stdlib.h>

#define N 6
#define M 7

int main() {
  int a[N][M];
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++)
      scanf("%d", &a[i][j]);
  for (int j = 0; j < N; j++) {
    int b = 0, logic = 1;
    while (logic) {
      logic = 0;
      for (int i = 0; i < M - 1 - b; i++) {
        if (a[j][i] < a[j][i+1]) {
          int k = a[j][i+1];
          a[j][i+1] = a[j][i];
          a[j][i] = k;
          logic = 1;
        }
      }
      b++;
    }
  }
  printf("\n");
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++)
      printf("%d ", a[i][j]);
    printf("\n");
  }
}