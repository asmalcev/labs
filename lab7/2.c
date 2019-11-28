#include "functions.c"

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

  char* line = (char*)malloc(200 * sizeof(char));
  while (!feof(file_r)) {
    fgets(line, 200, file_r);
    for (int i = 0; i < strlen(line); i++) {
      long long number = atoi(findNumber(line + i, &i));
      fprintf(file_w, "%lld", number % 2 ? number : number * 2);
      if (line[i] == '\n' || line[i] == ' ') fputc(line[i], file_w);
    }
  }

  free(line);
  printf("\n");
  printFile("output: ", file_w);
  fclose(file_r);
  fclose(file_w);
}