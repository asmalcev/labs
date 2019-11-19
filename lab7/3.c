#include "functions.c"

int main(int argc, char *argv[]) {
  char name[20] = "";
  if (argc == 1) {
    fgets(name, 20, stdin);
    name[strlen(name) - 1] = '\0';
  }
  else
    strcat(name, argv[1]);

  FILE *fr = fopen(name, "rb");
  FILE *fw = fopen("output.bin", "wb+");
  if (fr == NULL) {
    printf("can't open %s\n", name);
    remove("output");
    fclose(fw);
    return 1;
  }
  char* line = (char*)malloc(200 * sizeof(char));
  printFile("input:", fr);

  double first = 1, last;
  long indexF, indexL;
  while (!feof(fr)) {
    fgets(line, 200, fr);
    for (int i = 0, j = 0; i < strlen(line); i++, j++) {
      double number = atof(findNumber(line + i, &i));
      if (number < 0) {
        if (first > 0) {
          first = number;
          indexF = j;
        } else {
          last = number;
          indexL = j;
        }
      }
    }
  }
  fseek(fr, 0, SEEK_SET);

  while (!feof(fr)) {
    fgets(line, 200, fr);
    for (int i = 0, j = 0; i < strlen(line); i++, j++) {
      double number = atof(findNumber(line + i, &i));
      if (j == indexF)
        fprintf(fw, "%lf ", last);
      else if (j == indexL)
        fprintf(fw, "%lf ", first);
      else
        fprintf(fw, "%lf ", number);
    }
  }

  printFile("output: ", fw);

  free(line);
  fclose(fr);
  fclose(fw);
}