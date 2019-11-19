#include "functions.c"

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
      long long number = atoi(findNumber(line + i, &i));
      fprintf(fw, "%lld", number % 2 ? number : number * 2);
      if (line[i] == '\n' || line[i] == ' ') fputc(line[i], fw);
    }
  }

  free(line);
  printf("\n");
  printFile("output: ", fw);
  fclose(fr);
  fclose(fw);
}