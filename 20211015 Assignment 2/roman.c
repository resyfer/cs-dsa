#include <stdio.h>
#include <stdlib.h>

#define MAX 200

char symbols[13][3] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
int nums[13] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};

int numLength(char number[MAX]) {
  int length = MAX;
  for (int i = 0; i < MAX; i++)
  {
    if (number[i] == '\0')
    {
      length = i;
      break;
    }
  }
  return length;
}

int romanToDecimal(char number[MAX]) {
  int counter = 0;
  int size = numLength(number);

  for (int i = 0; i < size; i++) {
    for (int j = 12; j >= 0; j--) {
      if (number[i] == symbols[j][0]) {
        if (symbols[j][1] == '\0')
        {
          counter += nums[j];
          break;
        }
        else if (i + 1 < size && number[i + 1] == symbols[j][1])
        {
          counter += nums[j];
          i++;
          break;
        }
      }
    }
  }

  return counter;
}

char *decimalToRoman(int n) {

  char *number = (char *)malloc((MAX) * sizeof(char));
  for (int i = 0; i < MAX; i++)
    number[i] = 0;

  int index = 0;
  while (n)
  {
    for (int i = 12; i >= 0 && n; i--)
    {
      if (n >= nums[i])
      {
        n -= nums[i];

        number[index] = symbols[i][0];
        index++;

        if (symbols[i][1] >= 'A' && symbols[i][1] <= 'Z')
        {
          number[index] = symbols[i][1];
          index++;
        }

        break;
      }
    }
  }
  number[index] = '\0';
  return number;
}

int addNums(int num1, int num2) {
  return num1 + num2;
}

int multiplyNums(int num1, int num2) {
  return num1 * num2;
}

int main() {

  char inputNum1[MAX] = {0}, inputNum2[MAX] = {0};
  int num1, num2;

  printf("Enter number 1 > ");
  scanf("%s", inputNum1);
  num1 = romanToDecimal(inputNum1);

  printf("Enter number 2 > ");
  scanf("%s", inputNum2);
  num2 = romanToDecimal(inputNum2);

  int op;
  printf("\n");
  printf("1. Addition\n");
  printf("2. Multiplication\n");
  printf("Enter operation 1/2 > ");
  scanf("%d", &op);

  char *result;
  switch (op) {
  case 1:
    result = decimalToRoman(addNums(num1, num2));
    printf("Result > %s\n", result);
    break;

  case 2:
    result = decimalToRoman(multiplyNums(num1, num2));
    printf("Result > %s\n", result);
    break;

  default:
    printf("Invalid Operation\n");
    return 0;
    break;
  }
  free(result);
  return 0;
}