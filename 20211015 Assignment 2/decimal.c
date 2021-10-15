#include <stdio.h>

int addNums(int num1, int num2) {
  return num1 + num2;
}

int multiplyNums(int num1, int num2) {
  return num1*num2;
}

int main() {

  int num1, num2;
  
  printf("Enter number 1 > ");
  scanf("%d", &num1);

  printf("Enter number 2 > ");
  scanf("%d", &num2);

  int op;
  printf("\n");
  printf("1. Addition\n");
  printf("2. Multiplication\n");
  printf("Enter operation 1/2 > ");
  scanf("%d", &op);

  switch(op) {
    case 1:
      printf("Result > %d\n", addNums(num1, num2));
      break;
    
    case 2:
      printf("Result > %d\n", multiplyNums(num1, num2));
      break;

    default:
      printf("Invalid Operation\n");
      return 0;
      break;
  }

  return 0;
}