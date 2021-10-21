#include <stdio.h>
#include <limits.h>

#define MAX 536870911 //2**29 - 1
char primes[MAX+1] = {0};


void sieveOfEratosthenes(int n) {

  for(int i = 2; i*i<=n; i++) {
    // 0 -> Prime, 1 -> Non-prime
    if(primes[i] == 0) {
      for(int j = 2; j*i<=n; j++)
        primes[i*j] = 1;
    }
  }

}

void printPrimes(int n) {
  for(int i = 2; i<=n; i++) {
    if(primes[i] == 0)
      printf("%d ", i);
  }
  printf("\n");
}

int main() {

  int n;
  scanf("%d", &n);

  sieveOfEratosthenes(n);
  printPrimes(n);

  return 0;
}