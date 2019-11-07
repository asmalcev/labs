#include "functions.c"
#include <ctype.h>
#include <locale.h>

int isLowercase(char* word) {
  while(*word != '\0')
    if (*word == toupper(*word++))
      return 0;
  return 1;
}

int main(int argc, char *argv[]) {
  char name[20] = "";
  if (argc == 1) {
    fgets(name, 20, stdin);
    name[strlen(name) - 1] = '\0';
  }
  else
    strcat(name, argv[1]);
  
  FILE *fr = fopen(name, "r");
  FILE *fw = fopen("output", "w+");
  if (fr == NULL) {
    printf("can't open %s\n", name);
    remove("output");
    fclose(fw);
    return 1;
  }
  printFile("input: ", fr);

  char* line = (char*)malloc(200 * sizeof(char));
  while (!feof(fr)) {
    fgets(line, 200, fr);
    for (int i = 0; i < strlen(line); i++) {
      char* word = findWord(line + i, &i);
      if (isLowercase(word))
        fprintf(fw, "%s", word);
      if (line[i] == '\n'
      || line[i] == '.'
      || line[i] == ','
      || line[i] == ' ') fputc(line[i], fw);
    }
  }

  free(line);
  printf("\n");
  printFile("output: ", fw);
  fclose(fr);
  fclose(fw);
}