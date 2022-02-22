#include <stdio.h>
#include <stdlib.h>

//quickSelect is an algorithm that will aptly find the median in O(n) time.

//QuickSelect(A, k)
//  let r be chosen uniformly at random in the range 1 to length(A)
//  let pivot = A[r]
//  let A1, A2 be new arrays
//  # split into a pile A1 of small elements and A2 of big elements
//  for i = 1 to n
//    if A[i] < pivot then
//      append A[i] to A1
//    else if A[i] > pivot then
//      append A[i] to A2
//    else
//      # do nothing
//  end for
//  if k <= length(A1):
//    # it's in the pile of small elements
//    return QuickSelect(A1, k)
//  else if k > length(A) - length(A2)
//    # it's in the pile of big elements
//    return QuickSelect(A2, k - (length(A) - length(A2))
//  else
//    # it's equal to the pivot
//    return pivot

int quickSelect(int array[], int n, int k){

	if(n == 1 ) return array[0];

	int A1[n], A2[n];
	int a1 = 0, a2 = 0;
	int pivot = array[n-1];

	for(int i = 0; i<n; i++) {
		if(array[i] < pivot) {
			A1[a1] = array[i];
			a1++;
		}

		else if(array[i] > pivot) {
			A2[a2] = array[i];
			a2++;
		}
			printf("a1: %d\n", a1);
			printf("a2: %d\n", a2);
	}

	if (a1 >= k) return quickSelect(A1, a1, k);
	else if (k > a1+1) return quickSelect(A2, a2, k - (n - a2));
	else return pivot;

}



int main() {
	int a[7] = {1, 2, 5, 9, 4, 3, 7};	
	int d = quickSelect(a, 5,  3);

	printf("%d\n", d);
	return 0;
}

