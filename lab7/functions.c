#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printFile(char* title, FILE* fileName) {
  fseek(fileName, 0, SEEK_SET);
  char* line = (char*)malloc(200 * sizeof(char));
  
  printf("%s", title);
  while (!feof(fileName)) {
    fgets(line, 200, fileName);
    printf("%s", line);
  }
  printf("\n");
  
  free(line);
  fseek(fileName, 0, SEEK_SET);
}

char* findWord(char* line, int* index) {
  char* space = strchr(line, ' ');
  if (space == NULL)
    space = strchr(line, '\n');
  if (space == NULL) 
    space = strchr(line, '\0');
  char* sup = (char*)malloc((space - line) * sizeof(char));
  strncpy(sup, line, (space - line) * sizeof(char));
  *index += (int) (space - line);
  return sup;
}