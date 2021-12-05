#include <stdio.h>
#define LENA 10
#define LENB 10
#define LENC 20

int main()
{
  int arrA[LENA] = {1, 3, 4, 2, 5, 2, 6, 3, 6, 8};
  int arrB[LENB] = {2, 3, 2, 1, 20, 39, 92, 74, 2, 73};
  int arrC[LENC] = {0};
  for (int i = 0; i < LENA; i++)
  {
    arrC[i] = arrA[i];
  }

  for (int i = 0, j = LENA; i < LENB; i++)
  {
    j++;
    arrC[j] = arrB[i];
  }

  for (int i = 0; i < LENC; i++)
  {
    printf("%d ", arrC[i]);
  }
  return 0;
}