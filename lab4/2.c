#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
  int n, x, y, m, s;
  scanf("%d", &n);
  int *a = (int *)malloc(n * sizeof(int));
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  scanf("%d %d", &x, &y);
  m = y;
  if (y < 0) {
    printf("y < 0");
    return 0;
  }
  for (int i = 0; i < n; i++) {
    if (a[i] < m && a[i] >= x && a[i] <= y) {
      m = a[i];
      s = i;
    }
  }
  memcpy(a + s, a + s + 1, (n - s) * sizeof *a);
  for (int i = 0; i < n - 1; i++) printf("%d ", a[i]);
  free(a);
}