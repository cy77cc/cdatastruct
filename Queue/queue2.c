#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
#define MaxSize 10

typedef struct {
  int tag;
  ElemType data[MaxSize];
  int rear;
  int front;
} cycleQueue;

void InitQueue(cycleQueue *Q);

bool QueueEmpty(cycleQueue *Q);

void EnQueue(cycleQueue *Q, ElemType elem);

void DeQueue(cycleQueue *Q, ElemType *elem);

bool QueueFull(cycleQueue *Q);

int main() {
  cycleQueue q;
  InitQueue(&q);
  EnQueue(&q, 1);
  EnQueue(&q, 2);
  EnQueue(&q, 3);
  EnQueue(&q, 4);
  EnQueue(&q, 5);
  EnQueue(&q, 6);
  EnQueue(&q, 7);
  EnQueue(&q, 8);
  EnQueue(&q, 9);
  EnQueue(&q, 10);
  ElemType e;
  int i;
  for(i = 0; i < 10; i++) {
    DeQueue(&q, &e);
    printf("%d\n", e);
  }
  return 0;
}

void InitQueue(cycleQueue *Q) {
  cycleQueue *tmp = (cycleQueue *)malloc(sizeof(cycleQueue));
  tmp->front = 0;
  tmp->rear = 0;
  tmp->tag = 0;
  *Q = *tmp;
}

bool QueueEmpty(cycleQueue *Q) { return Q->front == Q->rear && Q->tag == 0; }
bool QueueFull(cycleQueue *Q) { return Q->front == Q->rear && Q->tag == 1; }

void EnQueue(cycleQueue *Q, ElemType elem) {
  if (QueueFull(Q)) {
    printf("队列满了\n");
    return;
  }
  Q->tag = 1;
  Q->data[Q->rear] = elem;
  Q->rear = (Q->rear + 1) % MaxSize;
}

void DeQueue(cycleQueue *Q, ElemType *elem) {
  if (QueueEmpty(Q)) {
    printf("队列已经空了\n");
    return;
  }
  Q->tag = 0;
  *elem = Q->data[Q->front];
  Q->front = (Q->front + 1) % MaxSize;
}