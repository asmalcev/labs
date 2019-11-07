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
  FILE *fw = fopen("output.bin", "w+b");
  if (fr == NULL) {
    printf("can't open %s\n", name);
    remove("output");
    fclose(fw);
    return 1;
  }

  char* line = (char*)malloc(200 * sizeof(char));
  while (!feof(fr)) {
    fgets(line, 200, fr);
    printf("%s", line);
  }
  printf("\n");
  
  free(line);
  fclose(fr);
  fclose(fw);
}