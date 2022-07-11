//10872 ÆÑÅä¸®¾ó (Àç±Í)
#include <stdio.h>

int fac(int n);

int main(void)
{
	int n;
	scanf("%d", &n);

	int result;
	result = fac(n);
	printf("%d", result);
	return 0;
}

int fac(int n) {

	if (n > 1)
		return n * fac(n - 1);
	else
		return 1;

	return 0;
}