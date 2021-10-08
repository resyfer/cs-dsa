#include <stdio.h>

int main() {
  int n, m;
  printf("Enter n m > ");
  scanf("%d %d", &n, &m);

  int k;
  printf("Enter k >");
  scanf("%d", &k);

  int i = (k / m), j = (k % m);
  printf("Element is at A[%d][%d]", i, j);
  return 0;
}