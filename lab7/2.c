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
  FILE *file_w = fopen("output2", "w+");
  if (file_r == NULL) {
    printf("can't open %s\n", file_name);
    remove("output");
    fclose(file_w);
    return 1;
  }
  printFile("input: ", file_r);

  long long number;
  while (!feof(file_r)) {
    fscanf(file_r, "%lld", &number);
    fprintf(file_w, "%lld ", number % 2 ? number : number * 2);
  }

  printf("\n");
  printFile("output: ", file_w);
  fclose(file_r);
  fclose(file_w);
}