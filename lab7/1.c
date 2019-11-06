#include "functions.c"

int isLowercase(char* word) {
  while(*word != '\0')
    if (*word > 'A' && *word++ < 'Z')
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
    return 0;
  }
  printFile("input: ", fr);

  char* line = (char*)malloc(200 * sizeof(char));
  while (!feof(fr)) {
    fgets(line, 200, fr);
    printf("line length = %ld\n", strlen(line));
    for (int i = 0; i < strlen(line); i++) {
      char* word = findWord(line + i, &i);
      printf("got %s\n", word);
      if (isLowercase(word)) {
        fprintf(fw, "%s", word);
        if (line[i] == ' ') fputs(" ", fw);
      }
      if (line[i] == '\n') fputs("\n", fw);
    }
  }

  free(line);
  printf("\n");
  printFile("output: ", fw);
  fclose(fr);
  fclose(fw);
}