#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef int DataType;

typedef struct LNode {
  DataType data;
  struct LNode *next;
} LinkNode;

void CreateListL(LinkNode **L);

void CreateListR(LinkNode **L);

void InitList(LinkNode **L);

void DestroyList(LinkNode *L);

bool ListEmpty(LinkNode *L);

int ListLength(LinkNode *L);

void DispList(LinkNode *L);
bool GetElem(LinkNode *L, int i, DataType *e);

LinkNode Merge(LinkNode LA, LinkNode LB);

int main() {
  LinkNode *LA = (LinkNode *)malloc(sizeof(LinkNode));
  LA->next = NULL;
  CreateListR(&LA);
  CreateListR(&LA);
  CreateListR(&LA);
  LinkNode *LB = (LinkNode *)malloc(sizeof(LinkNode));
  LB->next = NULL;
  CreateListR(&LB);
  CreateListR(&LB);
  CreateListR(&LB);

  // printf("线性表的长度是%d\n", ListLength(head));
  return 0;
}

void CreateListL(LinkNode **L) {
  LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
  DataType c;
  printf("输入值：");
  scanf("%d", &c);
  s->data = c;
  s->next = (*L)->next;
  (*L)->next = s;
}

void CreateListR(LinkNode **L) {
  LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
  DataType c;
  printf("输入值：");
  scanf("%d", &c);
  s->data = c;
  s->next = NULL;
  LinkNode *p = NULL;
  p = (*L);
  while (true) {
    if (p->next == NULL) {
      p->next = s;
      break;
    }
    p = p->next;
  }
}

void InitList(LinkNode **L) {
  (*L) = (LinkNode *)malloc(sizeof(LinkNode));
  (*L)->next = NULL;
}

void DestroyList(LinkNode *L) {
  LinkNode *pre = L, *p = L->next;
  while (p != NULL) {
    free(pre);
    pre = p;
    p = pre->next;
  }
  free(pre);
}

bool ListEmpty(LinkNode *L) { return (L->next == NULL); }

int ListLength(LinkNode *L) {
  int n = 0;
  LinkNode *p = L;
  while (p->next != NULL) {
    n++;
    p = p->next;
  }
  return n;
}

void DispList(LinkNode *L) {
  LinkNode *p = L->next;
  while (p != NULL) {
    printf("%d\n", p->data);
    p = p->next;
  }
}

bool GetElem(LinkNode *L, int i, DataType *e) {
  int j = 0;
  LinkNode *p = L;
  if (i <= 0) return false;
  while (j < i && p != NULL) {
    j++;
    p = p->next;
  }
  if (p == NULL)
    return false;
  else {
    e = p->data;
    return true;
  }
}