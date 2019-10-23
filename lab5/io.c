#include <stdio.h>
#include <stdlib.h>

int* readArray(int length) {
  int* arr = (int*) malloc(length * sizeof(int));
  for (short i = 0; i < length; i++)
    scanf("%d", &arr[i]);
  return arr;
}

void printArray(int* arr, int length) {
  for (short i = 0; i < length; i++)
    printf("%d ", arr[i]);
  printf("\n");
}