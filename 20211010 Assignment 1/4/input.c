#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX (int)1e4


void generateInput(int n, int input[]) {
  for(int i = 0; i<n; i++) {
    input[i] = rand()%MAX;
  }
}

int main() {

  srand(time(0));
  int n;
  scanf("%d", &n);
  int input[n];
  generateInput(n, input);

  FILE *inputFile = fopen("input.txt", "w");
  
  if (inputFile != NULL) {
    printf("Input File Generation Successfull !\n");
  }
  else {
    printf("Input File Generation Failed.\n");
    return -1;
  }
  
  fprintf(inputFile, "%d\n", n);
  for(int i = 0; i<n; i++) fprintf(inputFile, "%d ", input[i]);

  fclose(inputFile);

  return 0;
}