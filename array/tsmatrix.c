#include <stdio.h>

#define M 10
#define N 10
#define MaxSize 10

typedef struct {
  int r;
  int c;
  int d;
} TupNode;

typedef struct {
  int rows;
  int cols;
  int nums;
  TupNode data[MaxSize];
} TSMatrix;

void CreateMat(TSMatrix *t, int data[M][N]);
void TranTat(TSMatrix t, TSMatrix *tb);

int main() {
  int arr[M][N] = {
    {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    {0, 0, 2, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 3, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 4, 0, 0, 0, 0},
    {0, 0, 0, 5, 0, 0, 0, 0, 0, 0},
    {6, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 7, 0},
    {0, 0, 0, 0, 0, 0, 0, 8, 0, 0},
    {0, 0, 0, 0, 0, 9, 0, 0, 0, 0},
    {0, 0, 0, 0, 10, 0, 0, 0, 0, 0}
  };
  TSMatrix tsm, tb;
  CreateMat(&tsm, arr);
  TranTat(tsm, &tb);
  int i, j;
  for (i = 0; i < tsm.nums; i++) {
    printf("(%d, %d, %d)\n", tsm.data[i].r, tsm.data[i].c, tsm.data[i].d);
  }

  for (i = 0; i < tb.nums; i++) {
    printf("(%d, %d, %d)\n", tb.data[i].r, tb.data[i].c, tb.data[i].d);
  }
  int arr2[M][N] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  };
  for (i = 0; i < tb.nums; i++) {
    arr2[tb.data[i].r][tb.data[i].c] = tb.data[i].d;
  }
  for (i = 0; i < M; i++) {
    for (j = 0; j < N; j++) {
      printf("%d ", arr2[i][j]);
    }
    printf("\n");
  }
  return 0;
}

void CreateMat(TSMatrix *t, int data[M][N]) {
  int i, j;
  t->rows = M;
  t->cols = N;
  t->nums = 0;
  for (i = 0; i < M; i++) {
    for (j = 0; j < N; j++) {
      if (data[i][j] != 0) {
        TupNode node;
        node.r = i;
        node.c = j;
        node.d = data[i][j];
        t->data[t->nums] = node;
        t->nums++;
      }
    }
  }
}

void TranTat(TSMatrix t, TSMatrix *tb) {
  int i;
  tb->nums = t.nums, tb->cols = t.rows, tb->rows = t.cols;
  for (i = 0; i < t.nums; i++) {
    tb->data[i].r = t.data[i].c;
    tb->data[i].c = t.data[i].r;
    tb->data[i].d = t.data[i].d;
  }
}
