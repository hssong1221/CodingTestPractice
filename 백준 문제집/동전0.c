//11047 동전0 (그리디알고리즘)
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int n, k;
	scanf("%d", &n);
	scanf("%d", &k);

	int list[11];

	for (int i = 0; i < n; i++) {
		scanf("%d", &list[i]);
	}
	
	int temp1 = 0;
	int result = 0;
	for (int j = n - 1; 0 <= j; j--) {
		if (k < list[j])
			continue;
		else if (k >= list[j]) {
			temp1 = k / list[j];
			k = k % list[j];
			result += temp1;
		}
	}
	printf("%d", result);
	return 0;
}