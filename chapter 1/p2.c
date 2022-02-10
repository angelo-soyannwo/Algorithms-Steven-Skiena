

#include <stdlib.h>
#include <stdio.h>


void solution(int num, float a, float b, float c, float d) {
	float costs [] = {a, b, c, d},
	average = (a + b + c + d) / 4;
	float sum=0;
	for(int i=0; i<4; i++){
		if (costs[i] < average) {
			sum += (average - costs[i]);
		}
	}
	printf("%.2f", sum);
}

int main() {
	solution(4, 15, 15.01, 3, 3.01);

return 0;
}
