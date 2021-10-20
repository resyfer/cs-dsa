#include <stdio.h>
#include <limits.h>

#define MAX 536870911 //2**29 - 1

char primes[MAX+1] = {0};

void sieveOfEratosthenes() {

  for(int i = 2; i*i<=MAX; i++) {
    // 0 -> Prime, 1 -> Non-prime
    if(primes[i] == 0) {
      for(int j = 2; j*i<=MAX; j++)
        primes[i*j] = 1;
    }
  }

}

void printPrimes() {
  for(int i = 2; i<=MAX; i++) {
    if(primes[i] == 0)
      printf("%d ", i);
  }
  printf("\n");
}

int main() {

  sieveOfEratosthenes();
  printPrimes();

  return 0;
}