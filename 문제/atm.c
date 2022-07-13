//11399 ATM (그리디알고리즘)
#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
	int num1 = *(int*)a;
	int num2 = *(int*)b;

	if (num1 < num2)
		return -1;
	else if (num1 > num2)
		return 1;
	else
		return 0;
}
int main(void) {
	int n;
	scanf("%d", &n);

	int list[n];
	
	for (int i = 0; i < n; i++) 
		scanf("%d", &list[i]);

	qsort(list, sizeof(list)/sizeof(int), sizeof(int), compare);	// 퀵소트

	int temp = 0;													// 맨 앞에꺼는 n번 더해짐 그다음꺼는 n-1번 더해짐  
	for (int i = 0; i < n; i++) {
		temp = list[i] * (n - i) + temp;
	}
	printf("%d", temp);

	return 0;
}