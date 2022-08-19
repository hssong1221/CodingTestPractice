//9184 �ų��� �Լ� (DP)

#include <stdio.h>

int w(int a, int b, int c);

int abc[22][22][22];																	// abc�� 0���ϸ� 1�����̰� 20�̻��̿��� �����̶� 21���� �����

int main(void) {
	int a, b, c;
	int result;
	while (1) {
		
		scanf("%d", &a);
		scanf("%d", &b);
		scanf("%d", &c);

		if (a == -1 && b == -1 && c == -1)
			break;

		result = w(a, b, c);
		printf("w(%d, %d, %d) = %d\n", a, b, c, result);
	}
	return 0;
}

int w(int a, int b, int c) {
	if (0 <= a && a <= 20 && 0 <= b && b <= 20 && 0 <= c && c <= 20 && abc[a][b][c] != 0) { // ����س��� ���߿� �Ȱ����� �θ��� ������ ��
		return abc[a][b][c];
	}
	
	// ������ �ִ� ����
	if (a <= 0 || b <= 0 || c <= 0) 
		return 1;

	if (a > 20 || b > 20 || c > 20)
		return abc[20][20][20] = w(20, 20, 20);

	if (a < b && b < c) 
		return abc[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);

	return abc[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
}