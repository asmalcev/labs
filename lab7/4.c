#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct note {
  int id;
  char name[30];
  char speed[5];
  int deposit;
  char date[9];
};

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

char fileName[30];

void help() {
  printf(">> COMMAND - DESCRIPTION\n   c [FILENAME] - create or make clear if exists file [FILENAME]\n");
  printf("   o [FILENAME] - open file [FILENAME]\n   r [FILENAME] - remove file [FILENAME]\n   p [FILENAME] - print [FILENAME]\n   q - quit\n");
}

void fileHelp() {
  printf(">> EDITING FILE COMMAND:\n   COMMAND - DESCRIPTION\n   c [ID] [PERSON NAME] [CATEGORY] [DEPOSIT] [DATE] - create new note\n");
  printf("   p - print the bigest deposit\n   e [ID] [PERSON NAME] [CATEGORY] [DEPOSIT] [DATE] - change [ID] note \n");
  printf("   + [ID] [SUM] - get [SUM] from [ID] account\n   - [ID] [SUM] - put [SUM] on [ID] account\n   d [ID] - delete note [ID]\n   q - quit\n");
}

void clear(FILE* f) {
  while (getc(f) != '\n');
}

void deleteNote(int id, FILE* f) {
  FILE* newFile = fopen("supportFile.bin", "wb");
  fseek(f, 0, SEEK_SET);
  struct note memo;
  
  while (!feof(f)) {
    fscanf(f, "%d %s %s %d %s\n", &memo.id, memo.name, memo.speed, &memo.deposit, memo.date);
    if (id != memo.id) {
      fprintf(newFile, "%d %s %s %d %s\n", memo.id, memo.name, memo.speed, memo.deposit, memo.date);
    }
  }
  fseek(f, -1, SEEK_END);

  fclose(newFile);
  fclose(f);
  remove(fileName);
  rename("supportFile.bin", fileName);
  f = fopen(fileName, "ab+");
}

void editNote(int id, char* name, char* speed, int deposit, char* date, FILE* f) {
  FILE* newFile = fopen("supportFile.bin", "wb");
  fseek(f, 0, SEEK_SET);
  struct note memo;
  
  while (!feof(f)) {
    fscanf(f, "%d %s %s %d %s\n", &memo.id, memo.name, memo.speed, &memo.deposit, memo.date);
    if (id != memo.id)
      fprintf(newFile, "%d %s %s %d %s\n", memo.id, memo.name, memo.speed, memo.deposit, memo.date);
    else
      fprintf(newFile, "%d %s %s %d %s\n", memo.id, name, speed, deposit, date);
  }
  
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
  struct note memo;
  int maxDeposit = 0;
  
  while (!feof(f)) {
    fscanf(f, "%d %s %s %d %s\n", &memo.id, memo.name, memo.speed, &memo.deposit, memo.date);
    if(!strcmp(memo.speed, "fast")) {
      memo.deposit = memo.deposit;
      if (maxDeposit < memo.deposit)
        maxDeposit = memo.deposit;
    }
  }
  printf(">> The bigest deposit is %d\n", maxDeposit);
}

void changeDeposit(int id, int sum, short isSum, FILE* f) {
  FILE* newFile = fopen("supportFile.bin", "wb");
  fseek(f, 0, SEEK_SET);
  struct note memo;
  
  while (!feof(f)) {
    fscanf(f, "%d %s %s %d %s\n", &memo.id, memo.name, memo.speed, &memo.deposit, memo.date);
      if (id != memo.id) {
        fprintf(newFile, "%d %s %s %d %s\n", memo.id, memo.name, memo.speed, memo.deposit, memo.date);
      } else {
        int result = memo.deposit + sum * (isSum? 1 : -1);
        if (result >= 0)
          fprintf(newFile, "%d %s %s %d %s\n", memo.id, memo.name, memo.speed, result, memo.date);
      }
  }

  fclose(newFile);
  fclose(f);
  remove(fileName);
  rename("supportFile.bin", fileName);
  f = fopen(fileName, "ab+");
}

void fileWork(FILE* f) {
  int flag = 1, difference;
  char command;
  struct note memo;
  while (flag) {
    printf("<< ");
    scanf("%c", &command);

    switch (command) {
      case 'c':
        scanf("%d %s %s %d %s", &memo.id, memo.name, memo.speed, &memo.deposit, memo.date);
        clear(stdin);
        fprintf(f, "%d %s %s %d %s\n", memo.id, memo.name, memo.speed, memo.deposit, memo.date);
        fileDoc(f);
        break;

      case 'e':
        scanf("%d %s %s %d %s", &memo.id, memo.name, memo.speed, &memo.deposit, memo.date);
        clear(stdin);
        editNote(memo.id, memo.name, memo.speed, memo.deposit, memo.date, f);
        fileDoc(f);
        break;
      
      case 'd':
        scanf("%d", &memo.id);
        clear(stdin);
        deleteNote(memo.id, f);
        fileDoc(f);
        break;
      
      case 'p':
        clear(stdin);
        printBigestDeposit(f);
        break;
      
      case '+':
      case '-':
        scanf("%d %d", &memo.id, &difference);
        clear(stdin);
        changeDeposit(memo.id, difference, command == '+' ? 1 : 0, f);
        fileDoc(f);
        break;

      case 'q':
        flag = 0;
        clear(stdin);
        system("clear");
        help();
        break;

      default:
        clear(stdin);
        printf("error: unknown command\n");
        fileHelp();
    }
  }
}

int main() {
  system("clear");
  int flag = 1;
  char command;
  FILE *f;
  help();
  while (flag) {
    printf("<< ");
    scanf("%c", &command);

    switch (command) {
      case 'c':
        scanf("%s", fileName);
        clear(stdin);
        f = fopen(fileName, "wb");
        if (f == NULL)
          printf("error: could't create %s\n", fileName);
        else
          printf(">> %s is cleared and exists now\n", fileName);
        fclose(f);
        break;
      
      case 'r':
        scanf("%s", fileName);
        clear(stdin);
        f = fopen(fileName, "ab+");
        remove(fileName);
        printf(">> %s doesn't exist now\n", fileName);
        fclose(f);
        break;

      case 'p':
        scanf("%s", fileName);
        clear(stdin);
        f = fopen(fileName, "rb");
        printf(">> %s:\n", fileName);
        printFile(">> ", f);
        break;

      case 'o':
        scanf("%s", fileName);
        clear(stdin);
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
        clear(stdin);
        printf("error: unknown command\n");
        help();
    }
  }
}