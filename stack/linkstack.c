#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
  int x;
  int y;
} Coord;

typedef Coord ElemType;

typedef struct Node {
  ElemType data;
  struct Node *next;
} LinkStack;

void InitStack(LinkStack *LS);

void DestroyStack(LinkStack *LS);

bool StackEmpty(LinkStack *LS);

void Push(LinkStack *LS, ElemType e);

bool Pop(LinkStack *LS, ElemType *e);

bool GetTop(LinkStack *LS, ElemType *e);

// ElemType main() {
//   LinkStack stackHead;
//   ElemType e;
//   InitStack(&stackHead);
//   Push(&stackHead, 1);
//   Push(&stackHead, 2);
//   Push(&stackHead, 3);
//   Push(&stackHead, 4);
//   Push(&stackHead, 5);
//   GetTop(&stackHead, &e);
//   prElemTypef("%d\n", e);
//   Pop(&stackHead, &e);
//   prElemTypef("%d\n", e);
  
//   return 0;
// }

void InitStack(LinkStack *LS) {
  LinkStack *temp = (LinkStack *)malloc(sizeof(LinkStack));
  temp->next = NULL;
  *LS = *temp;
}

void DestroyStack(LinkStack *LS) {
  LinkStack *p = LS, *q = LS->next;
  while(q != NULL) {
    free(p);
    p = q;
    q = q->next;
  }
  free(p);
}

bool StackEmpty(LinkStack *LS) {
  return LS->next == NULL;
}

void Push(LinkStack *LS, ElemType e) {
  LinkStack *p;
  p = (LinkStack *)malloc(sizeof(LinkStack));
  p->data = e;
  p->next = LS->next;
  LS->next = p;
}

bool Pop(LinkStack *LS, ElemType *e) {
  if (LS->next == NULL) return false;
  LinkStack *p = LS->next, *q = p->next;
  *e = p->data;
  LS->next = q;
  free(p);
  return true;
}

bool GetTop(LinkStack *LS, ElemType *e) {
  if (LS->next == NULL) return false;
  *e = LS->next->data;
  return true;
}