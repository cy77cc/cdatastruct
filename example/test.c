#include <stdio.h>
#include <stdlib.h>

int fibonacci(int n) {
  int *C, i, j, sum, answer;
  C = malloc(sizeof(int) * (n+1));
  C[0] = 0;
  C[1] = 1;
  for (i = 2; i <= n; i++) {
    sum = 0;
    sum += C[i-1];
    sum += C[i-2];
    C[i] = sum;
  }
  answer = C[n];
  free(C);
  return answer;
}

int eval(int N) {
  int i, j;
  double sum, answer;
  double *C;
  C = malloc(sizeof(double) * (N + 1));
  C[0] = 1.0;
  for (i = 1; i <= N; i++) {
    // printf("C[%d] = %f")
    sum = 0.0;
    for (j = 0; j < i; j++) {
      sum += C[j];
    }
    C[i] = 2.0 * sum/i + i;
  }
  answer = C[N];
  free(C);
  return answer;
}

int main() {
  double res = eval(10);
  printf("res = %f\n", res);
  printf("fibonacci result is %d", fibonacci(10));
  return 0;
}