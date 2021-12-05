#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
#define MAXSIZE 10

typedef struct {
  ElemType data[MAXSIZE];
  int top;
} SqStack;

void InitStack(SqStack *s);
void DestroyStack(SqStack *s);
bool StackEmpty(SqStack s);
void Push(SqStack *s, ElemType e);
void Pop(SqStack *s, ElemType *e);
void GetTop(SqStack *s, ElemType *e);

int main() {
  SqStack stack;
  InitStack(&stack);
  int e;
  Push(&stack, 1);
  Push(&stack, 2);
  Push(&stack, 3);
  Push(&stack, 4);
  Push(&stack, 5);
  Pop(&stack, &e);
  printf("%d\n", e);
  Pop(&stack, &e);
  printf("%d\n", e);
  Pop(&stack, &e);
  printf("%d\n", e);
  Pop(&stack, &e);
  printf("%d\n", e);
  Pop(&stack, &e);
  printf("%d\n", e);
  return 0;
}

void InitStack(SqStack *s) {
  SqStack *temps = (SqStack *)malloc(sizeof(SqStack));
  temps->top = -1;
  *s = *temps;
}

void DestroySatck(SqStack *s) { free(s); }

bool StackEmpty(SqStack s) { return s.top == -1; }

void Push(SqStack *s, ElemType e) {
  if (s->top == MAXSIZE-1) return;
  s->data[s->top + 1] = e;
  s->top++;
}

void Pop(SqStack *s, ElemType *e) {
  if (s->top == -1) return;
  *e = s->data[s->top];
  s->top--;
}

void GetTop(SqStack *s, ElemType *e) {
  if (s->top == -1) return;
  *e = s->data[s->top];
}