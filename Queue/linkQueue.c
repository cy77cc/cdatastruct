#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ElemType;

typedef struct node {
  ElemType data;
  struct node *next;
} LinkList;

typedef struct queue {
  LinkList *front;
  LinkList *rear;
} LinkQueue;

void InitQueue(LinkQueue *Q) {
  Q->front = Q->rear = (LinkList *)malloc(sizeof(LinkList));
  if (Q->front == NULL) exit(1);
  
}

int main() {

  return 0;
}