#include "functions.c"
#include <ctype.h>

int main(int argc, char *argv[]) {
  char file_name[30] = "";
  if (argc == 1) {
    printf("Enter file name: ");
    scanf("%s", file_name);
  } else {
    strcat(file_name, argv[1]);
  }
  
  FILE *file_r = fopen(file_name, "r");
  FILE *file_w = fopen("output", "w+");
  if (file_r == NULL) {
    printf("can't open %s\n", file_name);
    remove("output");
    fclose(file_w);
    return 1;
  }
  printFile("input: ", file_r);

  char buffer[300], current_char = fgetc(file_r), phraseFlag = 0, wordFlag = 1, endFileFlag = 0;
  size_t j = 0;
  while (!endFileFlag) {
    switch (current_char) {
    case '.':
      buffer[j++] = '.';
      buffer[j] = '\0';
      j = 0;
      if (phraseFlag) {
        fputs(buffer, file_w);
      }
      phraseFlag = 0;
      wordFlag = 0;
      break;

    case EOF:
      buffer[j] = '\0';
      if (phraseFlag) {
        fputs(buffer, file_w);
      }
      endFileFlag = 1;
      break;

    case ' ':
      buffer[j++] = ' ';
      if (wordFlag == 1) {
        phraseFlag = 1;
      }
      wordFlag = 1;
      break;
    
    default:
      if (current_char != '\n' && (current_char == toupper(current_char) || (current_char >= -112 && current_char <= -81))) {
        wordFlag = 0;
      }
      buffer[j++] = current_char;
      break;
    }
    current_char = fgetc(file_r);
  }

  printf("\n");
  printFile("output: ", file_w);
  fclose(file_r);
  fclose(file_w);
}