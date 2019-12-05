#include <stdio.h>

struct note {
  int id;
  char name[30];
  char speed[5];
  int deposit;
  char date[9];
};

int main() {
  struct note memo;
  char input[] = "1 Alex fast 4000 19.11.12";

  sscanf(input, "%d %s %s %d %s", &memo.id, memo.name, memo.speed, &memo.deposit, memo.date);
  printf("%s has %d\n", memo.name, memo.deposit);
}