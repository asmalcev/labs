#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH 100

int main() {
  char* input = (char*) malloc(LENGTH * sizeof(char));
  char* output = (char*) malloc(LENGTH * sizeof(char));
  fgets(input, LENGTH * sizeof(char), stdin);
  for (short i = 0; i < strlen(input) - 1; i++) {
    if (input[i] == '%')
      strcat(output, "mod");
    else if (input[i] == 't' && input[i+1] == 'a' && input[i+2] == 'n') {
      
    } else
      strncat(output, &input[i], sizeof(char));
  }

  fputs(output, stdout);
  free(input);
  free(output);
}