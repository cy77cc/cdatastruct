#include <stdio.h>
#include <stdlib.h>

void heapsort(int arr[], int n) {
  if (n == 1) {
    return;
  }
  int j;
  for (j = n; j > 0; j--) {
    int depth = j / 2 - 1, i;
    for (i = depth; i >= 0; i--) {
      int topmax = i;
      int leftindex = 2 * i + 1;
      int rightindex = 2 * i + 2;
      if (leftindex <= j - 1 && arr[topmax] < arr[leftindex]) {
        topmax = leftindex;
      }
      if (rightindex <= j - 1 && arr[topmax] < arr[rightindex]) {
        topmax = rightindex;
      }
      if (topmax != i) {
        int tmp = arr[i];
        arr[i] = arr[topmax];
        arr[topmax] = tmp;
      }
    }
    int tmp = arr[0];
    arr[0] = arr[j-1];
    arr[j-1] = tmp;
  }
}

int main() {
  int arr[] = {11, 2, 32, 4, 15, 10, 6, 88, 39, 14};
  int n = sizeof(arr) / sizeof(int), i;
  heapsort(arr, n);
  for (i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  return 0;
}