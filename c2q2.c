

#include <stdio.h>


int main() {
	int turns = 0,
	n = 17,
	p = 1;
	while(p < n){
		p *= 9;
		turns+=1;
		printf("%d\n", p);
		if (p >= n){
			printf("Stan wins");
			break;}

		p *= 2;
		printf("%d\n", p);
		turns+=1;
		if (p >= n){
			printf("Ollie wins");
			break;}	
		
	}


return 0;
}
