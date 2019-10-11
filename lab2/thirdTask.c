#include <stdio.h>
#include <math.h>

int main() {
  int x1, y1, x2, y2, x3, y3;
  printf("white unit: ");
  scanf("%d %d", &x1, &y1);
  printf("black units: ");
  scanf("%d %d %d %d", &x2, &y2, &x3, &y3);
  if (abs(x1 - x2) == abs(y1 - y2))
    printf("yes\n");
  else if (abs(x1 - x3) == abs(y1 - y3))
    printf("yes\n");
  else
    printf("no\n");
}