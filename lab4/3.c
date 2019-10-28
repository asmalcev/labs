#include <stdio.h>
#include <stdlib.h>

#define N 3
#define M 3

int main() {
 double a[N][M];
  for (char i = 0; i < N; i++)
    for (char j = 0; j < M; j++)
      scanf("%le", &a[i][j]);

   for (char i = 0; i < N; i++) {
    for (char j = 0; j < M; j++)
      printf("%10lf ", a[i][j]);
    printf("\n");
  }
     
  for (char j = 0; j < N; j++) {
    char b = 0, flag = 1;
    while (flag) {
      flag = 0;
      for (char i = 0; i < M - 1 - b; i++) {
        if (a[j][i] < a[j][i+1]) {
          char k = a[j][i+1];
          a[j][i+1] = a[j][i];
          a[j][i] = k;
          flag = 1;
        }
      }
      b++;
    }
  }
  printf("\n");
  for (char i = 0; i < N; i++) {
    for (char j = 0; j < M; j++)
      printf("%10lf ", a[i][j]);
    printf("\n");
  }
}