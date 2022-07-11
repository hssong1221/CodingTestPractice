//9663 N-Queen (��Ʈ��ŷ)

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void Backtracking(int row);
bool Pruning(int row);

int n;
int col[16];
int temp = 0;


int main(void) {
	scanf("%d", &n);								// ü���� ũ��

	for (int i = 0; i < n; i++) {					//(0,0),(0,1)...(0,15)
		col[0] = i;									// ���� ������ - ��
		Backtracking(1);							// Ž������ 
	}
	printf("%d", temp);
	return 0;
}

void Backtracking(int row) {	
	if (row < n) {									
		for (int i = 0; i < n; i++) {				// �� ������
			col[row] = i;							// ��ǥ�ϴ� ���� i = �� row = ��

			if (Pruning(row)) {						// ������ ���� ������ Ž��
				Backtracking(row + 1);
			}
			else {									// ©������ �ٽ� �ʱ�ȭ
				col[row] = 0;
			}
		}
	}
	else {											// ü���� ũ�� �Ѿ�� ���Ž�� �Ϸ� �ȰŴϱ� ����Ǽ� +1
		temp++;										
	}
	
}
		
bool Pruning(int row) {							// �������� ���� ��� ����ġ��
	for (int i = 0; i < row; i++) {
		if (col[i] == col[row])					// �� �˻�
			return false;
		if (abs(col[i] - col[row]) == abs(i - row))  // �밢�� �˻� - ���� ���� ������ ���밪�� ������ �밢���� 
			return false;
	}
	return true;
}