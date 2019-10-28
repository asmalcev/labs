#include <stdio.h>

#define N 7
#define M 5

int main() {
  double a[N], b[M], s = 0;
  int n = 0;
  for (char i = 0; i < N; i++) 
    scanf("%le", &a[i]);
  for (char i = 0; i < M; i++)
    scanf("%le", &b[i]);
  for (char i = 0; i < N; i++) {
    char flag = 1;
    for (char j = 0; flag && j < M; j++)
      flag = a[i] == b[j] ? 0 : 1;
    if (flag) {
      s += a[i];
      n++;
    }
  }
    
  printf("%lf\n", n ? (double) s / n : 0);
}