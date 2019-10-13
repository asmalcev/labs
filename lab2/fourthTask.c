#include <stdio.h>

int main() {
  char a, b;
  for (char i = 10; i < 100; i++) {
    a = i % 10, b = i / 10;
    if (2*(a + b) == a*b)
      printf("%d\n", i);
  }
}