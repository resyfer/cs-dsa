#include <stdio.h>
#include <time.h>

int inputSize(FILE *inputFile) {
  int n;
  fscanf(inputFile, "%d", &n);
  return n;
}

void fileInput(FILE *inputFile, int n, int input[]) {

  for(int i = 0; i<n; i++)
    fscanf(inputFile, "%d", &input[i]);
}

void swapInts(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void selectionSort(int input[], int n) {
  for (int i = 0; i < n; i++) {
    int min = i;
    for (int j = i + 1; j < n; j++) {
      if(input[j] < input[min]) min = j;
    }
    swapInts(&input[min], &input[i]);
  }

}

int main() {
  FILE *inputFile = fopen("input.txt", "r");
  if (inputFile != NULL) {
    printf("Input File Successfully Opened !\n");
  }
  else {
    printf("Input File Opening Failed.\n");
    return -1;
  }

  int n = inputSize(inputFile);
  int input[n];

  fileInput(inputFile, n, input);

  clock_t start = clock();

  selectionSort(input, n);

  clock_t end = clock();
  printf("Total elapsed time : %f\n", (double)(end - start)/(double)CLOCKS_PER_SEC);
  fclose(inputFile);
  return 0;
}