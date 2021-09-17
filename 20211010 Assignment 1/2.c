#include <stdio.h>

#define MAX 50

int validDomain(char email[], int atIndex)
{
  int periodIndex = -1;
  if (email[atIndex + 1] != '.')
  {

    for (int i = atIndex + 2; i < MAX - 1; i++)
    {
      if (email[i] == '.')
        periodIndex = i;
    }

    if (periodIndex == -1)
      return 0;
    else
      return 1;
  }
  else
    return 0;
}

int isValidEmail(char email[])
{
  int atIndex = -1;
  for (int i = 0; i < MAX - 4; i++)
  {
    if (email[i] == '@')
      atIndex = i;
  }

  if (atIndex == -1)
    return 0;
  else
    return validDomain(email, atIndex);
}

int main()
{

  char email[MAX] = {0};
  scanf("%s", email);

  printf("The email is %s\n", ((isValidEmail(email)) ? "valid" : "invalid"));
  return 0;
}