//1193 분수찾기 (기본수학1단계)
#include <stdio.h>

int main(void)
{
	int n;
	scanf("%d", &n);

	int count = 1;
	int temp = 1;
	int dom;
	int mol;
	while (1) {
		if (temp < n)
			temp = temp + (++count);
		else
			break;
	}
	if (count % 2 == 1) {
		mol = 1 + (temp - n);
		dom = count - (temp - n);
	}
	else {
		mol = count - (temp - n);
		dom = 1 + (temp - n);
	}

	printf("%d/%d\n", mol, dom);
	return 0;
}

