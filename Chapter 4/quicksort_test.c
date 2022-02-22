#include "quicksort.h"
#include <stdio.h>

// main function
int main() {
  int array[] = {8, 7, 2, 1, 0, 9, 6};
  
  int n = sizeof(array) / sizeof(array[0]);
  
  printf("Unsorted Array\n");
  for(int i=0; i<n; i++) printf("%d, ", array[i]); 
  printf("\n");

  // perform quicksort on data
  quicksort(array, 0, n - 1);
  
  printf("Sorted array in ascending order: \n");
  for(int i=0; i<n; i++) printf("%d, ", array[i]); 
  printf("\n");
}

