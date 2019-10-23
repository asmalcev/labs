#include <stdio.h>

int main() {
  FILE *f = fopen("input", "r");
  if (f == NULL) {
    printf("can't open the file\n");
    return 0;
  }
  printf("%s\n", fgets());
}