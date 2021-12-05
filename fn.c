#include <stdio.h>
#include <math.h>

int solution(double a, double b, double c, double *x1, double *x2) {
  double d;
  d = b * b - 4 * a * c;
  if (d > 0) {
    *x1 = (-b + sqrt(d)) / (2 * a);
    *x2 = (-b - sqrt(d)) / (2 * a);
    return 2;
  } else if (d == 0) {
    *x1 = (-b) / (2 * a);
    return 1;
  } else {
    return 0;
  }
}

int main() {
  double x1;
  double x2;
  solution(2, 10, 4, &x1, &x2);
  printf("%f, %f", x1, x2);
  return 0;
}