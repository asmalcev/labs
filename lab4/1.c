#include <stdio.h>

#define N 10
#define M 5

int main() {
  int a[N], b[M], s = 0, n = 0;
  for (int i = 0; i < N; i++) 
    scanf("%d", &a[i]);
  for (int i = 0; i < M; i++)
    scanf("%d", &b[i]);
  for (int i = 0; i < N; i++) {
    int bool = 1;
    for (int j = 0; j < M; j++)
      if (a[i] == b[j]) {
        bool = 0;
        break;    
      }
    if (bool) {
      s += a[i];
      n++;
    }
  }
    
  printf("%f\n", n ? (float) s / n : 0);
}