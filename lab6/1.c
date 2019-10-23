#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH 100

int main() {
  char* str = (char*) malloc(LENGTH * sizeof(char));
  fgets(str, LENGTH * sizeof(char), stdin);
  char* p = strchr(str, '.');
  if (p == NULL) {
    printf("string doesn't have .\n");
    return 0;
  }
  short newLength = (int) (p-str) * sizeof(char);
  str = (char*) realloc(str, newLength);
  short k = 0, count = 0;
  for (short i = 0; i < newLength; i++) {
    if (str[i] != ' ')
      k++;
    else
      k = 0;
    if (k == 5)
      count++;
  }
  printf("%d\n", count);
  free(str);
}