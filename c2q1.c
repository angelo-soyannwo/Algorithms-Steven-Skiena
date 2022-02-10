

#include <stdio.h>
#include <math.h>

int countDigits(int num){
	int count = 0;
	while(num != 0){
		num = floor(num/10);
		count += 1;
	}
	return count;

}

int solution(int num1, int num2) {
	int digits = countDigits(num1),
	result = 0,
	carry = 0;

	for(int i=1; i<=digits; i++){
		int x =pow(10,i);
		int temp = num2%x;
		if ((temp + num1%x) >=x)
		carry+=1;
		num2 = num2-temp;
		num1 = num1-(num1%x);
	}
	
	return carry;
}


int main() {
//	for(int i=0; i<=4; i++){
//	printf("%f | ", pow(10,i));
//	printf("%d\n", countDigits(pow(10, i)));
//	}

	printf("%d\n", solution(123, 594));

	return 0;
}
