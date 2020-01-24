#include "functions.c"

int main(int argc, char *argv[]) {
  FILE* file = fopen("input.bin", "ab+");
  unsigned int b[8];

  fseek(file, 0 * sizeof(double), SEEK_SET);
  fread(b, sizeof(unsigned int), 1, file);

  fseek(file, 0, SEEK_END);
  fwrite(b, sizeof(unsigned int), 1, stdout);


  fclose(file);
}