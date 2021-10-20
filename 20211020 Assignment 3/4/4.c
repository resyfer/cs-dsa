#include <stdio.h>
#include "4.h"

int main() {

  int n;
  scanf("%d", &n);

  int *A = (int*) malloc(n*sizeof(int));
  for(int i = 0; i<n; i++)
    scanf("%d", &A[i]);

  DeleteSubset(A, n, 2, 4);

  for(int i = 0; i<3; i++)
    printf("%d ", A[i]);
  printf("\n");

  free(A);
  return 0;
}