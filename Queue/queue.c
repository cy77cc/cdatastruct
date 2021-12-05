#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "linkstack.c"
#define MaxSize 10
typedef int ElemType;

typedef struct {
  ElemType data[MaxSize];
  int front, rear;
} SqQueue;

void InitQueue(SqQueue *q);

void DestroyQueue(SqQueue *q);

bool QueueEmpty(SqQueue q);

bool enQueue(SqQueue *q, ElemType e);

bool deQueue(SqQueue *s, ElemType *e);

int main() {
  SqQueue q;
  return 0;
}

void InitQueue(SqQueue *q) {
  SqQueue *temp = (SqQueue *)malloc(sizeof(SqQueue));
  temp->front = temp->rear = -1;
  *q = *temp;
}

void DestroyQueue(SqQueue *q) { free(q); }

bool QueueEmpty(SqQueue q) { return q.front == q.rear; }

bool enQueue(SqQueue *q, ElemType e) {
  if (q->rear == MaxSize - 1) {
    printf("队列满了");
    return false;
  }
  q->rear = (q->rear + 1) % MaxSize;
  q->data[q->rear] = e;
  return true;
}

bool deQueue(SqQueue *q, ElemType *e) {
  if (q->front == q->rear) {
    printf("队列已经空了");
    return false;
  }
  q->front = (q->front +  1) % MaxSize;
  *e = q->data[q->front];
  return true;
}