#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printFile(char* title, FILE* file_name) {
  fseek(file_name, 0, SEEK_SET);
  double x;
  printf("%s", title);
  while(fread(&x, sizeof(double), 1, file_name));
    printf("%lf ", x);
  printf("\n");
}
 
int main() {
  FILE* file = fopen("input.bin", "ab+");
  if (file == NULL) {
    printf("Error opening file");
    return 1;
  }
  printFile("file: ", file);

  char *line = (char*)malloc(100 * sizeof(char));
  double num;
  fgets(line, 100, stdin);
  line[strlen(line) - 1] = ' ';
  while (strcmp(line, "end ") != 0) {
    if (strcmp(line, "clear ") == 0) {
      freopen("input.bin", "wb+", file);
      printFile("file: ", file);
    } else {
      num = atof(line);
      fwrite(&num, sizeof(double), 1, file);
    }
    fgets(line, 100, stdin);
    line[strlen(line) - 1] = ' ';
  }
  printFile("file: ", file);
  
  free(line);
  fclose(file);
}