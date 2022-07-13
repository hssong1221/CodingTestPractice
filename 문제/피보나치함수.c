//1003 �Ǻ���ġ�Լ� (DP)

#include <stdio.h>

int main(void) {
	int t;
	scanf("%d", &t);

	int fibo[41] = { 0,1,1 };
	for (int i = 3; i < 41; i++) {
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	}

	int temp;
	for (int i = 0; i < t; i++) {
		scanf("%d", &temp);
		if (temp == 0) {
			printf("1 0\n");
		}
		else if (temp == 1) {
			printf("0 1\n");
		}
		else {
			printf("%d %d\n", fibo[temp - 1], fibo[temp]);
		}
	}
	return 0;
}

/*
	������ ��Ģ����
	�Ǻ���ġ ����   : 0,1,1,2,3,5,8,13,21...
	0�� ��µǴ�Ƚ��: 1,0,1,1,2,3,5,8,13,21...
	1�� ��µǴ�Ƚ��: 0,1,1,2,3,5,8,13,21...
	*/