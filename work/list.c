#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10

typedef struct {
  int data[MAXSIZE];
  int length;
} SqList;

typedef struct Node {
  int data;
  struct Node *next;
} LinkList;

// 创建顺序表，arr初始化的数据元素，n是长度
void CreateSqlist(SqList **L, int arr[], int n);

// 分割顺序表
void SplitSqlist(SqList *L, SqList **LA, SqList **LB);

// 输出顺序表
void DispList(SqList *L);

// 初始化单链表，arr数据，n是arr有多少个数据
void InitLinkList(LinkList *L, int arr[], int n);

// 拆分L单链表
void SplitLinkList(LinkList *L, LinkList *LA, LinkList *LB);

// 输出单链表
void DispLinkList(LinkList *L);

int main() {
  printf("===================顺序表实现=================\n");
  SqList *L;
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  CreateSqlist(&L, arr, 10);
  printf("L: ");
  DispList(L);
  SqList *LA, *LB;
  SplitSqlist(L, &LA, &LB);
  printf("LA: ");
  DispList(LA);
  printf("LB: ");
  DispList(LB);
  printf("===================单链表实现=================\n");
  LinkList List;
  LinkList ListA;
  LinkList ListB;

  InitLinkList(&List, arr, 10);
  SplitLinkList(&List, &ListA, &ListB);
  printf("List: ");
  DispLinkList(&List);
  printf("ListA: ");
  DispLinkList(&ListA);
  printf("ListB: ");
  DispLinkList(&ListB);

  return 0;
}

void CreateSqlist(SqList **L, int arr[], int n) {
  int i;
  (*L) = (SqList *)malloc(sizeof(SqList));
  if (n == 0) {
    (*L)->length = 0;
    return;
  };
  for (i = 0; i < n; i++) {
    (*L)->data[i] = arr[i];
  }
  (*L)->length = n;
}

void SplitSqlist(SqList *L, SqList **LA, SqList **LB) {
  int i;
  int num1 = 0, num2 = 0;
  int arr1[MAXSIZE], arr2[MAXSIZE];
  for (i = 0; i < L->length; i++) {
    if (L->data[i] % 2 != 0) {
      arr1[num1] = L->data[i];
      num1++;
    } else {
      arr2[num2] = L->data[i];
      num2++;
    }
  }
  CreateSqlist(LA, arr1, num1);
  CreateSqlist(LB, arr2, num2);
}

void DispList(SqList *L) {
  int i;
  for (i = 0; i < L->length; i++) {
    printf("%d ", L->data[i]);
  }
  printf("\n");
}

void InitLinkList(LinkList *L, int arr[], int n) {
  LinkList *p = L;
  int i;
  for (i = 0; i < n; i++) {
    LinkList *temp = (LinkList *)malloc(sizeof(LinkList));
    temp->data = arr[i];
    temp->next = NULL;
    p->next = temp;
    p = p->next;
  }
}

void SplitLinkList(LinkList *L, LinkList *LA, LinkList *LB) {
  LinkList *p = L, *p2 = LA, *p3 = LB;
  while (p->next != NULL) {
    p = p->next;
    LinkList *temp = (LinkList *)malloc(sizeof(LinkList));
    temp->data = p->data;
    temp->next = NULL;
    if (p->data % 2 != 0) {
      p2->next = temp;
      p2 = p2->next;
    } else {
      p3->next = temp;
      p3 = p3->next;
    }
  }
  p2->next = NULL;
  p3->next = NULL;
}

void DispLinkList(LinkList *L) {
  LinkList *p = L;
  while (p->next != NULL) {
    p = p->next;
    printf("%d ", p->data);
  }
  printf("\n");
}
