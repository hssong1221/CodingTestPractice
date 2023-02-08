//2577 숫자의 갯수 (1차원 배열)
#include <stdio.h>

int main(void)
{
	int a, b, c;
	int result;
	int temp;
	int num[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &c);

	result = a * b * c;
	while (result > 0) {
		temp = result % 10;
		num[temp]++;
		result /= 10;
	}
	for (int i = 0; i < 10; i++)
		printf("%d\n", num[i]);

	return 0;
}