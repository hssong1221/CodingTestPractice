//11399 ATM (�׸���˰���)
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

	qsort(list, sizeof(list)/sizeof(int), sizeof(int), compare);	// ����Ʈ

	int temp = 0;													// �� �տ����� n�� ������ �״������� n-1�� ������  
	for (int i = 0; i < n; i++) {
		temp = list[i] * (n - i) + temp;
	}
	printf("%d", temp);

	return 0;
}