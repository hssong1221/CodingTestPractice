// 1436 영화감독숌(브루트포스)
#include <stdio.h>

int main(void) {
	int n;
	scanf("%d", &n);

	int count = 0;
	int number = 666;
	int temp;

	while (1) {
		temp = number;
		while (1) {
			if (temp % 1000 == 666) {
				count++;
				break;
			}
			if (temp == 0)
				break;
			temp /= 10;
			
		}
		if(count == n)
			break;
		
		number++;
	}
	printf("%d ", number);
	return 0;
}

