#include "functions.c"

int main(int argc, char *argv[]) {
  char file_name[30] = "";
  if (argc == 1) {
    printf("Enter file name: ");
    scanf("%s", file_name);
  } else {
    strcat(file_name, argv[1]);
  }

  FILE *file_r = fopen(file_name, "rb");
  FILE *file_w = fopen("output.bin", "wb+");
  if (file_r == NULL) {
    printf("can't open %s\n", file_name);
    remove("output");
    fclose(file_w);
    return 1;
  }
  printFile("input: ", file_r);

  double number, first = 1, last;
  long indexF, indexL, countNegative = 0, j;
  while (!feof(file_r)) {
    fscanf(file_r, "%lf", &number);
    if (number < 0) {
      if (first > 0) {
        first = number;
        indexF = j;
      } else {
        last = number;
        indexL = j;
      }
      countNegative++;
    }
    j++;
  }
  fseek(file_r, 0, SEEK_SET);
  j = 0;

  while (!feof(file_r)) {
    fscanf(file_r, "%lf", &number);
    if (j == indexF) {
      fprintf(file_w, "%lf ", last);
    } else if (j == indexL) {
      fprintf(file_w, "%lf ", first);
    } else {
      fprintf(file_w, "%lf ", number);
    }
    j++;
  }
  fprintf(file_w, "%ld ", countNegative);
  printf("\n");
  printFile("output: ", file_w);

  fclose(file_r);
  fclose(file_w);
}