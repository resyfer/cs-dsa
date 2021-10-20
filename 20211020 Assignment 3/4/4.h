#include <stdio.h>
#include <stdlib.h>

//a
void InsertItemAtLast(int A[], int n, int key) {
  A = (int*) realloc(A, n+1);
  A[n] = key;
}

//b
void InsertItemAtFirst(int A[], int n, int key) {
  A = (int*) realloc(A, n+1);

  for(int i = n; i>0; i--)
    A[i] = A[i-1];
  A[0] = key;
}

//c
void InsertItemAtIndex(int A[], int n, int i, int key) {
  A = (int*) realloc(A, n+1);

  for(int j = n; j>i; j--)
    A[j] = A[j-1];
  A[i] = key;
}

//d
void DeleteItemFromLast(int A[], int n) {
  A = (int*) realloc(A, n-1);
}

//e
void DeleteItemFromFirst(int A[], int n) {
  
  for(int i = 0; i<n-1; i++)
    A[i] = A[i+1];

  A = (int*) realloc(A, n-1);
}

//f
void DeleteItemFromIndex(int A[], int n, int i) {
  for(int j = i; j<n-1; j++)
    A[j] = A[j+1];
  A = (int*) realloc(A, n-1);
}

//g
int FindItemUnsorted(int A[], int n, int key) {
  for(int i = 0; i<n; i++) {
    if(A[i] == key)
      return i;
  }
  return -1;
}

//h
int binarySearch(int A[], int n, int key, int low, int high) {
  int mid = (low + high) / 2;

  if(low > high)
    return -1;
  else if(A[mid] == key)
    return mid;
  else if (A[mid] > key)
    return binarySearch(A, n, key, 0, mid-1);
  else
    return binarySearch(A, n, key, mid+1, n-1);
}

int FindItemSorted(int A[], int n, int key) {
  return binarySearch(A, n, key, 0, n-1);
}

//i
void SortArray(int A[], int n) {
  int key, j;
  for (int i = 1; i < n; i++) {
    key = A[i];
    j = i - 1;

    while (j >= 0 && A[j] > key) {
      A[j + 1] = A[j];
      j = j - 1;
    }
    A[j + 1] = key;
  }
}

//j
int *ExtractSubest(int A[], int n, int i, int j) {

  int size = j-i+1;
  int *subset = (int*) malloc(size * sizeof(int));

  for(int k = 0; k<size; k++)
    subset[k] = A[i+k];

  return subset;
}

//k
int DeleteSubset(int A[], int n, int i, int j) {
  int size = (n -j) + (i-1);

  for(int k = j+1; k<n; k++)
    A[(k-j) + (i-1)] = A[k];
  A = (int*) realloc(A, size);
}