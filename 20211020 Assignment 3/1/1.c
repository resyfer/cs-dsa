#include <stdio.h>

#define MAX 200

long long int hashString(char input[MAX]) {

  long long int hash = 0;
  for(int i = 0; i<MAX && input[i]!='\0'; i++) {
    hash+=(i+1)*input[i];
  }
  return hash;
}

int main() {

  char input[MAX] = {0};

  scanf("%[^\n]", input);

  printf("%lld\n", hashString(input));

  return 0;
}