#include <stdio.h>

int main() {
  int a, b;
  for (int i = 10; i < 100; i++) {
    a = i % 10, b = i / 10;
    if (2*(a + b) == a*b)
      printf("%d\n", i);
  }
}