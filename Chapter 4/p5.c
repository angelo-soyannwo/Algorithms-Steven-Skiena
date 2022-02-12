#include <stdlib.h>
#include <stdio.h>


int main() {
	int array [10];

//generate a sorted set of contiguous data	
	int counter = 0;
	for(int j=1; j<5; j++){
		for (int z=1; z<(j+1); z++){
			array[counter] = j;
			counter++;
		}
	}

	for(int k=0; k<10; k++)
		printf("%d\n", array[k]);

//step through logic for the algorithm where the number of elements in the array is 10 
	int n = 10;
	int var = array[0];
	int current_count = 0;
	int max_count = 0;
	int mode;
	int current_elem = array[0];


	for(int i=0; i<n; i++) {
		if (array[i] == var){
			current_count += 1;

			if(i ==(n-1) && current_count > max_count){
                                max_count = current_count;
                                mode = array[i-1];
                                var = array[i];
                                current_count = 0;
                        }
		}

			
		if(array[i] != var){
			if(current_count > max_count){
				max_count = current_count;
				mode = array[i-1];
				var = array[i];
				current_count = 1;
			}
		}
	}

	printf("---\n");
	printf("%d\n", mode);
}
