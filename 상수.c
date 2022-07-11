//2908 상수 (문자열)
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char a[4];
	char b[4];
	scanf("%s", a);
	scanf("%s", b);

	int temp;
	temp = a[0];
	a[0] = a[2];
	a[2] = temp;

	temp = b[0];
	b[0] = b[2];
	b[2] = temp;

	int c, d;
	c = atoi(a);
	d = atoi(b);
	if (c > d)
		printf("%d\n", c);
	else
		printf("%d\n", d);

	return 0;
}