//10818 최대 최소 (1차원 배열)
#include <stdio.h>

int main(void)
{
	int n;
	int min = 10000001;
	int max = -1000001;
	int temp;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &temp);
		if (temp < min) {
			min = temp;
		}

		if (max < temp) {
			max = temp;
		}
	}
	printf("%d %d", min, max);
	return 0;
}