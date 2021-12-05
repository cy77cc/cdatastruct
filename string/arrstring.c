#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MaxSize 30

typedef struct {
  char data[MaxSize];
  int length;
} SqString;

void StrAssgin(SqString *s);
int StrEqual(SqString S, SqString T);

int main() {
  SqString S;
  SqString T;
  StrAssgin(&S);
  StrAssgin(&T);
  printf("%d", StrEqual(S, T));
  return 0;
}

void StrAssgin(SqString *s) {
  char cstr[MaxSize];
  printf("请输入：");
  scanf("%s", cstr);
  int i;
  for (i = 0; cstr[i] != '\0'; i++) {
    s->data[i] = cstr[i];
  }
  s->length = i;
}

int StrEqual(SqString S, SqString T) {
  int i, j, count;
  bool flag = true;
  for (i = 0; i <= S.length-T.length; i++) {
    for (j = 0; j < T.length; j++) {
      if (S.data[i+j] != T.data[j]) {
        flag = false;
      }
    }
    if (flag) {
      count++;
    }
    flag = true;
  }
  return count;
}