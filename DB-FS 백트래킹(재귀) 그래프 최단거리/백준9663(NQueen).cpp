#include <iostream>
#include <vector>

using namespace std;

// (�ε��� - ��, �� - ��)
vector<int> col(16, 0);
// ü���� ũ��
int board;
// ����
int answer = 0;

void DFS(int n) {
	// �ִ� ���� ���� ����
	if (n == board)
		answer++;
	else {
		for (int k = 0; k < board; k++) {
			// �� ��ġ
			col[n] = k;
			// �÷���
			bool flag = true;

			// ���� �� ���� �� �ֳ� Ȯ��
			for (int i = 0; i < n; i++) {
				flag = false;
				// ���� ���ο� �ְ� �밢���̶�� �Ÿ���
				if (col[n] == col[i] || abs(col[n] - col[i]) == abs(n - i))
					break;
				// ������ ����ϸ� �� ��ġ ����
				if (i == n - 1)
					flag = true;
			}
			if (flag)
				DFS(n + 1);
		}
	}
}



int main() {
	// �Է�
	cin >> board;
	// �� -  ���� ���� �밢�� ���� ���� ��ġ ������ �ִ� ���� ������ ���� ũ��� ����
	// ���� �࿡�ٰ� ���� �� �����Ƿ� ���� �࿡�� �ü� �ִ� ���� �Ǵ��ϸ� �ȴ�
	DFS(0);

	cout << answer;
	return 0;
}

