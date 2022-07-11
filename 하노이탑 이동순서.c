//11729 하노이탑이동순서 (재귀)
#include <stdio.h>

void hanoi(int n, int from, int to, int remaining);
void hanoi2(int n, int from, int to, int remaining);
int temp = 0;

int main(void)
{
	int n;
	scanf("%d", &n);

	hanoi2(n, 1, 3, 2);
	printf("%d\n", temp);
	hanoi(n, 1, 3, 2);

	return 0;
}

void hanoi(int n, int from, int to, int remaining) {
	if (n <= 1) {
		printf("%d %d \n", from, to);
		return;
	}

	hanoi(n - 1, from, remaining, to);
	printf("%d %d \n", from, to);
	hanoi(n - 1, remaining, to, from);
}

void hanoi2(int n, int from, int to, int remaining) {

	if (n <= 1) {
		temp++;
		return;
	}
	hanoi2(n - 1, from, remaining, to);
	temp++;
	hanoi2(n - 1, remaining, to, from);
}