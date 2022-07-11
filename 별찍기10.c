//2477 º°Âï±â10 (Àç±Í)
#include <stdio.h>

void Star10(int n, int x, int y);
char xy[2188][2188];

int main(void)
{
	int n;
	scanf("%d", &n);

	Star10(n, 0, 0);

	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			if (xy[i][k] == '\0') {
				printf(" ");
				continue;
			}
			printf("%c", xy[i][k]);
		}
		printf("\n");
	}
	return 0;
}

void Star10(int n, int x, int y) {
	int temp = 0;
	temp = n/3;

	if (n == 1) {
		xy[x][y] = '*';
		return;
	}

	for (int i = 0; i < 3; i++) {
		for (int k = 0; k < 3; k++) {
			if (i != 1 || k != 1)
				Star10(temp, x + i * temp, y + k * temp);
		}
	}
	
}