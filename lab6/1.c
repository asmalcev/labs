#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH 100

int main() {
  char* str = (char*) malloc(LENGTH * sizeof(char));
  fgets(str, LENGTH * sizeof(char), stdin);
  if (strchr(str, '.') == NULL) {
    printf("string doesn't have .\n");
    return 0;
  }
  short k = 0, count = 0;
  for (short i = 0; i < strlen(str) - 2; i++) {
    if (str[i] != ' ' && str[i] != ',')
      k++;
    else {
      if (k >= 5)
        count++;
      k = 0;
    }
  }
  printf("%d\n", count);
  free(str);
}