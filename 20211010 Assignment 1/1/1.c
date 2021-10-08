#include <stdio.h>

#define MAX 100

int floatingNumValid(char num[])
{
  /**
   * Floating number valid if there's a number after .
  */
  int isValidFloat = 0;
  for (int i = 0; i < MAX - 1; i++)
  {
    if (num[i] == '.' && num[i + 1] != 0)
      isValidFloat = 1;
  }
  return isValidFloat;
}

int main()
{
  char num[MAX] = {0};
  printf("Enter number > ");
  scanf("%s", num);

  printf("Floating number is %s\n", ((floatingNumValid(num)) ? "valid" : "invalid"));

  return 0;
}