#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
  short n, s;
  double x, y;
  scanf("%hd", &n);
  double *a = (double *)malloc(n * sizeof(double)), * i;
  for (i = a; i - a < n; i++) scanf("%le", i);
  scanf("%le %le", &x, &y);
  if (y < 0) {
    printf("y < 0");
    return 0;
  }
  for (i = a; i - a < n; i++) {
    if (*i < y && *i >= x) {
      y = *i;
      s = (short) (i - a);
    }
  }
  memcpy(a + s, a + s + 1, (n - s) * sizeof *a);
  for (i = a; i - a < n - 1; i++) printf("%lf ", *i);
  printf("\n");
  free(a);
}