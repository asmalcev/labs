#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void printFile(char* title, FILE* fileName) {
  fseek(fileName, 0, SEEK_SET);
  
  printf("%s\n", title);
  int ch = fgetc(fileName);
  while (ch != EOF) {
    putchar(ch);
    ch = fgetc(fileName);
  }
  
  fseek(fileName, 0, SEEK_SET);
}

char* fileName;

void help() {
  printf(">> COMMAND - DESCRIPTION\n   c [FILENAME] - create or make clear if exists file [FILENAME]\n");
  printf("   o [FILENAME] - open file [FILENAME]\n   r [FILENAME] - remove file [FILENAME]\n   p [FILENAME] - print [FILENAME]\n   q - quit\n");
}

void fileHelp() {
  printf(">> EDITING FILE COMMAND:\n   COMMAND - DESCRIPTION\n   c [ID] [PERSON NAME] [CATEGORY] [DEPOSIT] [DATE] - create new note\n");
  printf("   p - print the bigest deposit\n   e [ID] [PERSON NAME] [CATEGORY] [DEPOSIT] [DATE] - change [ID] note \n");
  printf("   - [ID] [SUM] - get [SUM] from [ID] account\n   - [ID] [SUM] - put [SUM] on [ID] account\n   d [ID] - delete note [ID]\n   q - quit\n");
}

void deleteNote(char* id, FILE* f) {
  FILE* newFile = fopen("supportFile.bin", "wb");
  fseek(f, 0, SEEK_SET);
  char* line = (char*)malloc(200 * sizeof(char));
  
  while (!feof(f)) {
    fgets(line, 200, f);
    char* lineId = strtok(line, " ");
    char* lineOther = strtok(NULL, "");
    if (strcmp(lineId, id) != 0 && lineOther != NULL && lineId != NULL) {
      fprintf(newFile, "%s %s", lineId, lineOther);
    }
  }
  fseek(f, -1, SEEK_END);

  free(line);
  fclose(newFile);
  fclose(f);
  remove(fileName);
  rename("supportFile.bin", fileName);
  f = fopen(fileName, "ab+");
}

void editNote(char* id, char* newData, FILE* f) {
  FILE* newFile = fopen("supportFile.bin", "wb");
  fseek(f, 0, SEEK_SET);
  char* line = (char*)malloc(200 * sizeof(char));
  
  while (!feof(f)) {
    fgets(line, 200, f);
    char* lineId = strtok(line, " ");
    char* lineOther = strtok(NULL, "");
    if (lineOther != NULL) {
      if (strcmp(lineId, id) != 0)
        fprintf(newFile, "%s %s", lineId, lineOther);
      else
        fprintf(newFile, "%s %s\n", lineId, newData);
    }
  }
  
  free(line);
  fclose(newFile);
  fclose(f);
  remove(fileName);
  rename("supportFile.bin", fileName);
  f = fopen(fileName, "ab+");
}

void fileDoc(FILE* f) {
  system("clear");
  fileHelp();
  printf(">> %s:\n", fileName);
  printFile(">> ", f);
}

void printBigestDeposit(FILE* f) {
  fseek(f, 0, SEEK_SET);
  char* line = (char*)malloc(200 * sizeof(char)),
      * lineId,
      * name,
      * speed;
  long long deposit, maxDeposit = 0;
  
  while (!feof(f)) {
    fgets(line, 200, f);
    lineId = strtok(line, " ");
    name = strtok(NULL, " ");
    if (name != NULL) {
      speed = strtok(NULL, " ");
      if(!strcmp(speed, "fast")) {
        deposit = atoi(strtok(NULL, " "));
        if (maxDeposit < deposit)
          maxDeposit = deposit;
      }
    }
  }
  printf(">> The bigest deposit is %lld\n", maxDeposit);
  
  free(line);
}

void changeDeposit(char* id, char* sum, short isSum, FILE* f) {
  FILE* newFile = fopen("supportFile.bin", "wb");
  fseek(f, 0, SEEK_SET);
  char* line = (char*)malloc(200 * sizeof(char)),
      * lineId,
      * lineOther;
  
  while (!feof(f)) {
    fgets(line, 200, f);
    lineId = strtok(line, " ");
    lineOther = strtok(NULL, "");
    if (lineOther != NULL) {
      if (strcmp(lineId, id) != 0) {
        fprintf(newFile, "%s %s", lineId, lineOther);
      } else {
        char* name = strtok(lineOther, " "),
            * speed = strtok(NULL, " "),
            * deposit = strtok(NULL, " ");
        lineOther = strtok(NULL, "");
        long long result =  atoi(deposit) + atoi(sum) * (isSum? 1 : -1);
        if (result >= 0)
          fprintf(newFile, "%s %s %s %lld %s", lineId, name, speed, result, lineOther);
      }
    }
  }
  free(line);
  fclose(newFile);
  fclose(f);
  remove(fileName);
  rename("supportFile.bin", fileName);
  f = fopen(fileName, "ab+");
}

void fileWork(FILE* f) {
  int flag = 1;
  char* inputString = (char*)malloc(100 * sizeof(char)),
      * command,
      * option1, 
      * option2;
  while (flag) {
    printf("<< ");
    fgets(inputString, 200, stdin);
    inputString[strlen(inputString) - 1] = '\0';
    command = strtok(inputString, " ");

    switch (*inputString) {
      case 'c':
        fprintf(f, "%s\n", strtok(NULL, ""));
        fileDoc(f);
        break;

      case 'e':
        option1 = strtok(NULL, " "), option2 = strtok(NULL, "");
        editNote(option1, option2, f);
        fileDoc(f);
        break;
      
      case 'd':
        deleteNote(strtok(NULL, " "), f);
        fileDoc(f);
        break;
      
      case 'p':
        printBigestDeposit(f);
        break;
      
      case '+':
        option1 = strtok(NULL, " "), option2 = strtok(NULL, "");
        changeDeposit(option1, option2, 1, f);
        fileDoc(f);
        break;

      case '-':
        option1 = strtok(NULL, " "), option2 = strtok(NULL, "");
        changeDeposit(option1, option2, 0, f);
        fileDoc(f);
        break;

      case 'q':
        flag = 0;
        system("clear");
        help();
        break;

      default:
        printf("error: unknown command\n");
        fileHelp();
    }
  }

  free(inputString);
}

int main() {
  system("clear");
  int flag = 1;
  char* inputString = (char*)malloc(100 * sizeof(char)), * command;
  FILE *f;
  help();
  while (flag) {
    printf("<< ");
    fgets(inputString, 100, stdin);
    inputString[strlen(inputString) - 1] = '\0';
    command = strtok(inputString, " ");

    switch (*inputString) {
      case 'c':
        fileName = strtok(NULL, "");
        f = fopen(fileName, "wb");
        if (f == NULL)
          printf("error: could't create %s\n", fileName);
        else
          printf(">> %s is cleared and exists now\n", fileName);
        fclose(f);
        break;
      
      case 'r':
        fileName = strtok(NULL, "");
        f = fopen(fileName, "ab+");
        remove(fileName);
        printf(">> %s doesn't exist now\n", fileName);
        fclose(f);
        break;

      case 'p':
        fileName = strtok(NULL, "");
        f = fopen(fileName, "rb");
        printf(">> %s:\n", fileName);
        printFile(">> ", f);
        break;

      case 'o':
        fileName = strtok(NULL, "");
        f = fopen(fileName, "ab+");
        if (f == NULL)
          printf("error: could't open %s\n", fileName);
        else {
          fileDoc(f);
          fileWork(f);
        }
        fclose(f);
        printf(">> %s closed\n", fileName);
        break;

      case 'q':
        flag = 0;
        break;
      
      default:
        printf("error: unknown command\n");
        help();
    }
  }

  free(inputString);
}