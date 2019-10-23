#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH 200

char* parse(char* input, int length) {
  char* output = (char*) malloc(length * sizeof(char));
  for (short i = 0; i < strlen(input); i++) {
    if (input[i] == '%')
      strcat(output, "mod");
    else if (input[i] == 't' && input[i+1] == 'a' && input[i+2] == 'n') {
      char* bracket = strchr(input + i, ')');
      char* sup = (char*) malloc(length * sizeof(char));
      strncpy(sup, input + i + 3, (bracket - input - i - 2) * sizeof(char));
      short k = 0, k1 = 1;
      for (short j = 0; j < strlen(sup); j++)
        if (sup[j] == '(')
          k++;
      while (k1 < k) {
        bracket++;
        if (bracket[0] == ')')
          k1++;
      }
      strncpy(sup, input + i + 3, (bracket - input - i - 2) * sizeof(char));
      printf("sup = %s\n", sup);
      i += strlen(sup) + 2;
      strcat(output, "sin");
      strcat(output, sup);
      strcat(output, " / cos");
      strcat(output, sup);
      free(sup);
    } else
      strncat(output, &input[i], sizeof(char));
  }
  if (strchr(output, '%') != NULL || strstr(output, "tan") != NULL)
    output = parse(output, length);
  free(input);  
  return output;
}

int main() {
  char* str = (char*) malloc(LENGTH * sizeof(char));
  fgets(str, LENGTH * sizeof(char), stdin);
  str = parse(str, LENGTH);
  fputs(str, stdout);
  free(str);
}