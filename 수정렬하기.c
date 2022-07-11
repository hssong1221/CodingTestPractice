//2750 수정렬하기(정렬)

#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
	int num1 = *(int *)a;
	int num2 = *(int *)b;

	if (num1 > num2)
		return -1;
	else if (num1 < num2)
		return 1;
	else
		return 0;
}

int main(void) {
	int n;
	scanf("%d", &n);

	int list[1001]={0,};

	for (int i = 0; i < n; i++) {
		scanf("%d", &list[i]);
	}

	qsort(list, sizeof(list) / sizeof(int), sizeof(int), compare);

	for (int i = n-1; 0 <= i ; i--) {
		printf("%d\n", list[i]);
	}

	return 0;
}