#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH 200

char* parse(const char* input, const int length);

int main() {
  char* str = (char*) malloc(LENGTH * sizeof(char));
  char* resultStr;
  fgets(str, LENGTH * sizeof(char), stdin);
  resultStr = parse(str, LENGTH);
  fputs(resultStr, stdout);
  free(str);
  free(resultStr);
}

char* parse(const char* input, const int length) {
  char* output = (char*) malloc(length * sizeof(char));
  for (short i = 0; i < strlen(input); i++) {
    if (input[i] == '%') {

      strcat(output, "mod");

    } else if (strstr(input + i, "tan") - input == i) {

      char* bracket = strchr(input + i, '(');
      short countOfBrackets = 1;

      while (countOfBrackets > 0) {
        bracket++;
        if (*bracket == '(') {
          countOfBrackets++;
        }
        if (*bracket == ')') {
          countOfBrackets--;
        }
      }

      char* sup = (char*) malloc((bracket - input - i - 2) * sizeof(char));
      strncpy(sup, input + i + 3, (bracket - input - i - 2) * sizeof(char));
      i += strlen(sup) + 2;

      if (strstr(sup, "tan") != NULL || strchr(sup, '%') != NULL)
        sup = parse(sup, strlen(sup));

      strcat(output, "sin");
      strcat(output, sup);
      strcat(output, " / cos");
      strcat(output, sup);
      free(sup);

    } else {

      short posDiv = strchr(input + i, '%') - input - i;
      short posTg  = strstr(input + i, "tan") - input - i;
      short countOfSymb;
      
      if (posDiv < 0 && posTg < 0) {
        strcat(output, input + i);
        break;
      } else if (posDiv < 0) {
        countOfSymb = posTg;
      } else if (posTg < 0) {
        countOfSymb = posDiv;
      } else {
        countOfSymb = posTg > posDiv ? posDiv : posTg;
      }

      strncat(output, input + i, countOfSymb * sizeof(char));
      i += countOfSymb - 1;
    }
  }
  
  return output;
}