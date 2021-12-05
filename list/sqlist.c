#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define Maxsize 50

typedef struct {
  int data[10];
  int length;
} SqList;

void CreateList(SqList **L, int arr[], int n);
void InitList(SqList **L);
void DestroyList(SqList **L);
bool ListEmpty(SqList *L);
int ListLenght(SqList *L);
void DispList(SqList *L);
bool GetElem(SqList *L, int i, int *e);
int LocateElem(SqList *L, int e);
bool ListInsert(SqList **L, int i, int e);
bool ListDelete(SqList **L, int i, int *e);

int main() {
  int n = 5;
  int i;
  int num[] = {2, 3, 1, 7, 8};

  SqList *L;
  InitList(&L);
  for (i = 0; i < n; i++) {
    ListInsert(&L, i+1, num[i]);
  }
  DispList(L);
  int elem;
  ListDelete(&L, 2, &elem);
  DispList(L);

  return 0;
}

// 建立顺序表
void CreateList(SqList **L, int arr[], int n) {
  int i;
  *L = (SqList *)malloc(sizeof(SqList));
  (*L)->length = n;
  for (i = 0; i < n; i++) {
    (*L)->data[i] = arr[i];
  }
}

// 初始化线性表
void InitList(SqList **L) {
  *L = (SqList *)malloc(sizeof(SqList));
  (*L)->length = 0;
}

// 销毁线性表
void DestroyList(SqList **L) { free(*L); }

// 判断线性表是否为空， bool要引入stdbool.h
bool ListEmpty(SqList *L) { return (L->length == 0); }

// 求线性表长度
int ListLenght(SqList *L) { return L->length; }

// 输出线性表
void DispList(SqList *L) {
  int i;
  for (i = 0; i < L->length; i++) {
    printf("%d ", L->data[i]);
  }
  printf("\n");
}

// 求线性表中的某个数据元素值
bool GetElem(SqList *L, int i, int *e) {
  if (i < 1 || i > L->length) return false;
  *e = L->data[i];
  return true;
}

// 按元素查找
int LocateElem(SqList *L, int e) {
  int i = 0;
  while (i < L->length && L->data[i] != e) {
    i++;
  }
  if (i >= L->length)
    return 0;
  else
    return i + 1;
}

// 插入数据元素
bool ListInsert(SqList **L, int i, int e) {
  int j;
  if (i < 1 || i > (*L)->length + 1 || (*L)->length == Maxsize) {
    return false;
  }
  i--;
  for (j = (*L)->length; j > i; j--) {
    (*L)->data[j] = (*L)->data[j - 1];
  }
  (*L)->data[i] = e;
  (*L)->length++;
  return true;
}

bool ListDelete(SqList **L, int i, int *e) {
  int j;
  if (i < 1 || i > (*L)->length) {
    return false;
  }

  *e = (*L)->data[i - 1];

  for (j = i; j < (*L)->length - 1; j++) {
    (*L)->data[j] = (*L)->data[j + 1];
  }

  (*L)->length--;

  return true;
}
