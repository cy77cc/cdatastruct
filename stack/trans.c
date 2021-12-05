#include <stdio.h>
#include <stdlib.h>

#include "linkstack.c"

LinkStack s;
void trans(int num, int r) {
  if (num == 1 || num == 0) {
    Push(&s, num);
    return;
  }
  int a = num % r;
  num = num / r;
  Push(&s, a);
  trans(num, r);
}

int main() {
  InitStack(&s);
  trans(20, 2);
  int e;
  while(!StackEmpty(&s)) {
    Pop(&s, &e);
    printf("%d", e);
  }
  return 0;
}