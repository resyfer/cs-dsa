#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX (int)1e4


void generateRandomInput(int n, int input[]) {
  for(int i = 0; i<n; i++)
    input[i] = rand()%MAX;
}

void generateSortedInput(int n, int input[]) {
  for(int i = 0; i<n; i++)
    input[i] = i;
}

int main() {

  srand(time(0));
  int n;
  printf("Enter size of input > ");
  scanf("%d", &n);

  int input[n];

  int k;
  printf("\n");
  printf("1. Randomly Generated\n");
  printf("2. Already Sorted\n");
  printf("Enter type of input 1/2 > ");
  scanf("%d", &k);

  switch(k) {
    case 1:
      generateRandomInput(n, input);
      break;

    case 2:
      generateSortedInput(n, input);
      break;
    
    default:
      printf("Incorrect option\n");
      return 0;
      break;
  }

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