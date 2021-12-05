#include <stdio.h>
#include <stdlib.h>

typedef struct DNode {
  int data;
  struct DNode *pre;
  struct DNode *next;
} DLinkNode;

void CreateListF(DLinkNode **L, int data[], int n) {
  DLinkNode *s;
  int i;
  (*L) = (DLinkNode *)malloc(sizeof(DLinkNode));
  (*L)->next = (*L)->pre = NULL;
  for (i = 0; i < n; i++) {
    s = (DLinkNode *)malloc(sizeof(DLinkNode));
    s->data = data[i];
    s->next = (*L)->next;
    if ((*L)->next != NULL) {
      (*L)->next->pre = s;
    }
    (*L)->next = s;
    s->pre = (*L);
  }
}

void CreateListR(DLinkNode **L, int data[], int n) {
  DLinkNode *s, *r;
  int i;
  (*L) = (DLinkNode *)malloc(sizeof(DLinkNode));
  r = L;
  for (i = 0; i < n; i++) {
    s = (DLinkNode *)malloc(sizeof(DLinkNode));
    s->data = data[i];
    r->next = s;
    s->pre = r;
    r = s;
  }
  r->next = NULL;
}

void main() {}