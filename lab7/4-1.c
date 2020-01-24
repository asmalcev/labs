#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct note {
  int id;
  char name[30];
  char speed[5];
  int deposit;
  char date[9];
};

void add(char*);
void show(char*);
void delete(char*);
void search_fast(char*);

void main() {
  FILE *f;
  char file[80] = {'\0'};
  int menu;
  while(1) {
    system("clear");
    if (file[0] == '\0')
      puts("FILE DIDN'T CHOOSE");
    else
      printf("FILE: %s\n", file);
    
    puts("s - show notes");
    puts("f - find the biggest deposit from category 'fast'");
    puts("a - add note");
    puts("c - create file");
    puts("d - delete race");
    puts("o - open file");
    puts("q - quit\n");
    menu = getchar();

    switch(menu) {
      case 's':
        show(file);
        break;
      case 'f':
        search_fast(file);
        break;
      case 'a':
        add(file); 
        break;
      case 'c':
        puts("Enter name");
        scanf("%s", file);
        f = fopen(file, "wb");
        fclose(f);
        break;
      case 'd':
        delete(file);
        break;
      case 'o':
        puts("Enter name");
        scanf("%s", file);
        break;
      case 'q':
        return;
    }
  }
}

struct note input_note(void) {
  struct note note;
  getchar();
  puts("Enter note id");
  scanf("%d", &note.id);
  puts("Enter name");
  scanf("%s", note.name);
  puts("Enter category");
  scanf("%s", note.speed);
  puts("Enter deposit");
  scanf("%d", &note.deposit);
  puts("Enter date");
  scanf("%s", note.date);

  return note;
};

void printf1(struct note data) {
  printf("ID: %d\nName: %s\nCategory: %s\nDeposit: %d\nDate of last operation: %s\n\n", data.id, data.name, data.speed, data.deposit, data.date);
}

void show(char *file) {
  FILE *f;
  int page, b = 0;
  struct note note;
  int notes = 0, c = 0, sdvig = sizeof(note)*6;

  system("clear");
  if ((f=fopen(file, "a+b")) == NULL) {
    return;
  }

  fseek(f, 0, SEEK_END);
  int length = ftell(f) / sizeof(note);
  int length1 = ftell(f) / sizeof(note);
  fseek(f, 0, SEEK_SET);
  puts("| ID | Name | Category | Deposit | date |");
  puts("+---+--------------------+------+---------+------------+");
  while(fread(&note, sizeof(note), 1, f)) {
    printf("|%-3d|%-20s|%-6s|%9d|%10s|\n", note.id, note.name, note.speed, note.deposit, note.date);
    puts("+---+--------------------+------+---------+----------+");
    c++;
    b++;
    notes++;
    if(notes == 3 && b == 3) {
      b = 0;
      if(notes == c) {
        puts("Next page : 1\nReturn : any button");
        scanf("%d", &page);
        if(page == 1) {
          notes = 0;
          length1 -= 3;
          system("clear");
          puts("| ID | Name | Category | Deposit | date |");
          puts("+---+--------------------+------+---------+----------+");
        } else {
          puts("bye");
          break;
        }
        getchar();
      } else if(c == length) {
        puts("Last page : 2\nReturn : any button");
        scanf("%d", &page);
        if(page==2) {
          fseek(f, -sizeof(note)*6, SEEK_END);
          length1+=3;
          c-=6;
          notes=0;
          system("clear");
          puts("| ID | Name | Category | Deposit | date |");
          puts("+---+--------------------+------+---------+----------+");
        } else {
          puts("bye");
          break;
        }
        getchar();
      } else {
        puts("Next page: 1\nLast page : 2\nReturn : any button");
        scanf("%d", &page);
        if(page == 1) {
          notes=0;
          length1-=3;
          system("clear");
          puts("| ID | Name | Category | Deposit | date |");
          puts("+---+--------------------+------+---------+----------+");
        } else if(page == 2) {
          length1+=3;
          fseek(f, -sizeof(note)*6, SEEK_CUR);
          c-=6;
          notes=0;
          system("clear");
          puts("| ID | Name | Category | Deposit | date |");
          puts("+---+--------------------+------+---------+----------+");
        } else {
          puts("bye");
          break;
        }
        getchar();
      }
    } else if (length1 == 2 && b == 2) {
      b = 0;
      puts("Last page : 2\nReturn : any button");
      scanf("%d", &page);
      if (page == 2) {
        length1 += 3;
        fseek(f, -sizeof(note) * 5, SEEK_END);
        c -= 5;
        notes = 0;
        system("clear");
          puts("| ID | Name | Category | Deposit | date |");
        puts("+---+--------------------+------+---------+----------+");
      } else {
        puts("bye"); 
        break;
      }
      getchar();
    } else if (length1 == 1 && b == 1) {
      b = 0;
      puts("Last page : 2\nReturn : any button");
      scanf("%d", &page);
      if (page == 2) {
        length1 += 3;
        fseek(f, -sizeof(note)*4, SEEK_END);
        c -= 4;
        notes = 0;
        system("clear");
          puts("| ID | Name | Category | Deposit | date |");
        puts("+---+--------------------+------+---------+----------+");
      } else {
        puts("bye");
        break;
      }
      getchar(); ot
    }
  }
  fclose(f);
  return;
}

void add(char *file) {
  FILE *f;
  struct note note;
  if ((f=fopen(file, "ab")) == NULL) {
    return;
  }

  note = input_note();
  fwrite(&note, sizeof(note), 1, f);
  fclose(f);
  return;
}

void search_fast(char *file) {
  FILE *f;
  struct note note;
  struct note maxNote;
  maxNote.deposit = 0;

  if ((f=fopen(file, "rb")) == NULL) {
    return;
  }

  while (fread(&note, sizeof(note), 1, f))
    if(note.deposit > maxNote.deposit)
      maxNote = note;
  printf1(maxNote);
  return;
}

void delete(char *file) {
  FILE *f1, *f2;
  struct note note;
  int id;
  if ((f1 = fopen(file, "rb")) == NULL || (f2 = fopen("helper.bin", "wb")) == NULL) {
    return;
  }

  puts("Print race number");
  scanf("%d", &id);
  fseek(f1, 0, SEEK_SET);
  while (fread(&note, sizeof(note), 1, f1)) {
    if (id != note.id)
      fwrite(&note, sizeof(note), 1, f2);
  }

  fclose(f1);
  fclose(f2);
  remove(file);
  rename("helper.bin", file);
  return;
}