#include <stdlib.h>
#include <stdio.h>

void solution(int i, int j){
	int count,
	max = 0;
	for(i; i<=j; i++){
		int n=i;
		count=1;
		while(n!=1){
			if (n%2 == 1) {
				n=3*n +1;
			}
			else {
				n/=2;
			}
			count+=1;
			if (max < count){
				max = count;
			}
		}
	} 
	printf("max is: %d\n", max);
}

int main() {
	solution(1, 10);
	solution(100, 200);
	solution(201, 210);
	solution(900, 1000);

	return 0;
}


