#include "functions.c"
 
int main() {
  FILE* file = fopen("input.bin", "wb+");
  if (file == NULL) {
    printf("Error opening file");
    return 1;
  }

  char *line = (char*)malloc(100 * sizeof(char));
  fgets(line, 100, stdin);
  line[strlen(line) - 1] = ' ';
  while (strcmp(line, "end ") != 0) {
    fprintf(file, "%lf ", atof(line));
    fgets(line, 100, stdin);
    line[strlen(line) - 1] = ' ';
  }
  printFile("file:", file);
  
  free(line);
  fclose(file);
}