// 2798 블랙잭(브루트포스)
#include <stdio.h>

int main(void) {
	int num;
	int goal;
	int list[101] = { 0, };

	scanf("%d", &num);
	scanf("%d", &goal);

	for (int i = 0; i < num; i++) {
		scanf("%d", &list[i]);
	}

	int temp = 0;
	int sum;
	int n = 0;

	for (int i = 0; i < num - 2; i++) {
		for (int j = i + 1; j < num - 1; j++) {
			for (int k = j + 1 ; k < num; k++) {
				sum = list[i] + list[j] + list[k];
				if (temp < sum && sum <= goal)
					temp = sum;
			}
		}
	}

	printf("%d", temp);
	return 0;
}

