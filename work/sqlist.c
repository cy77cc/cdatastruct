#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int data[10];
  int length;
} Sqlist;

void CreateList(Sqlist *L, int arr[], int n) {
  Sqlist *temp = (Sqlist *)malloc(sizeof(Sqlist));
  int i;
  for (i = 0; i < n; i++) {
    temp->data[i] = arr[i];
  }
  temp->length = n;
  *L = *temp;
}

void main() {
  Sqlist LA;
  int arr[] = {1, 2, 3, 4, 5, 6};
  int n = 6, i;
  printf("%p\n", &LA);
  CreateList(&LA, arr, n);
  printf("%p\n", &LA);
  printf("%d\n", LA.length);
  for (i = 0; i < n; i++) {
    printf("%d ", LA.data[i]);
  }
}