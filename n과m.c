//15649 n��m (��Ʈ��ŷ - DFS�� ��ͷ� ����)

#include <stdio.h>
#include <stdbool.h>

void Backtraking(int a);

int n, m;
int save[9];							// �������� �س��� ��� ���鼭 �� ���� �ϰ� �س���
bool visit[10];							// �������� �س��� ��� ���鼭 �ߴ����� ���ߴ����� ����

int main(void) {
	scanf("%d", &n);
	scanf("%d", &m);
	
	Backtraking(0); // �� ó�� ��ġ
	return 0;
}

void Backtraking(int a) {
	if (a == m) {						// �� �Ʒ��� ������ ����
		for (int i = 0; i < m; i++) {
			printf("%d ", save[i]);		// ����� ���� ��� m����
		}
		printf("\n");
	}
	else {								// ���� Ž����
		for (int i = 1; i <= n; i++) {	// �ڿ����� 1���� ������
			if (!visit[i]) {			// ó������
				visit[i] = true;		// �Դٰ� ǥ��
				save[a] = i;			// �׸��� �� ����
				Backtraking(a + 1);		// �� ���� ���� ��
				visit[i] = false;		// �ٽ� �ʱ�ȭ 
			}	
		}	
	}
}