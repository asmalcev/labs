#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

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
  char* border,
      * space = strchr(line, ' '),
      * point = strchr(line, '.'),
      * comma = strchr(line, ',');
  border = abs(space - line) > abs(point - line) ?
           abs(point - line) > abs(comma - line) ? comma : point :
           abs(space - line) > abs(comma - line) ? comma : space;
  
  if (border == NULL)
    border = strchr(line, '\n');
  if (border == NULL) 
    border = strchr(line, '\0');
  char* sup = (char*)malloc((border - line) * sizeof(char));
  strncpy(sup, line, (border - line) * sizeof(char));
  *index += (int) (border - line);
  return sup;
}

char* findNumber(char* line, int* index) {
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