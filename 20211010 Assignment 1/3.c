#include <stdio.h>

void convertTo1D(int n, int m, int twoDArray[][m], int oneDArray[]) {
  for(int i = 0; i<n*m; i++)
    oneDArray[i] = twoDArray[i/m][i%m];
}

int main() {

  int n, m;
  printf("Enter 2D Array Dimensions > ");
  scanf("%d %d", &n, &m);

  int array[n][m], A[n*m];

  printf("Enter the 2D Array\n");
  for(int i = 0; i<n; i++)
    for(int j = 0; j<m; j++) scanf("%d", &array[i][j]); 
  printf("\n");

  convertTo1D(n, m, array, A);

  printf("1D Array:\n");
  for(int i = 0; i<n*m; i++) printf("%d ", A[i]);
  printf("\n");

  return 0;
}