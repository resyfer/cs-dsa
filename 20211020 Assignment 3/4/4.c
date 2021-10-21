#include "4.h"

int main() {

  int n;
  scanf("%d", &n);

  // int *A = (int*) malloc(n*sizeof(int));
  int *B;
  int *A = AllocateArray(n, B);
  
  for(int i = 0; i<n; i++)
    A[i] = i+1;

  for(int i = 0; i<n; i++)
    printf("%d ", A[i]);
  printf("\n");

  for(int i = 0; i<n; i++)
    printf("%d ", B[i]);
  printf("\n");
  return 0;
}