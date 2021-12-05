#include <stdbool.h>
#include <stdio.h>

#include "linkstack.c"

int maze[12][12] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, {1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1}, {1, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1},
    {1, 1, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1}, {1, 1, 0, 1, 0, 1, 0, 0, 1, 1, 1, 1},
    {1, 1, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1}, {1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1},
    {1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1}, {1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1},
    {1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1}, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
};

int main() {
  Coord start;
  start.x = 1;
  start.y = 1;
  Coord end;
  end.x = 10;
  end.y = 10;
  LinkStack s, result;
  InitStack(&s);
  InitStack(&result);
  Push(&s, start);
  bool flag = false;
  while (!StackEmpty(&s)) {
    Coord now;
    GetTop(&s, &now);
    int x = now.x, y = now.y;
    if (x == end.x && y == end.y) {
      flag = true;
      printf("出来了\n");
      while (!StackEmpty(&s)) {
        Coord temp;
        Pop(&s, &temp);
        Push(&result, temp);
      }
      while (!StackEmpty(&result)) {
        Coord temp;
        Pop(&result, &temp);
        printf("(%d, %d) ", temp.x, temp.y);
      }
      printf("\n");
      break;
    }
    maze[x][y] = 2;
    Coord next;
    if (maze[x - 1][y] == 0) {
      next.x = x - 1;
      next.y = y;
      Push(&s, next);
    } else if (maze[x][y + 1] == 0) {
      next.x = x;
      next.y = y + 1;
      Push(&s, next);
    } else if (maze[x + 1][y] == 0) {
      next.x = x + 1;
      next.y = y;
      Push(&s, next);
    } else if (maze[x][y - 1] == 0) {
      next.x = x;
      next.y = y - 1;
      Push(&s, next);
    } else {
      Coord temp;
      Pop(&s, &temp);
    }
  }

  if (!flag) {
    printf("这个迷宫走不通");
  }
  DestroyStack(&s);
  DestroyStack(&result);
  // getchar();
  return 0;
}