#include <iostream>
#include <vector>

using namespace std;

// (�ε��� - ��, �� - ��)
vector<int> col(16, 0);
// ü���� ũ��
int board;
// ����
int answer = 0;

// ������� �˻� �ĳ���
bool prunning(int n) {
	for (int i = 0; i < n; i++) {
		// ���� ���ο� �ְ� �밢���̶�� �Ÿ���
		if (col[n] == col[i] || abs(col[n] - col[i]) == abs(n - i))
			return false;
	}
	return true;
}

void DFS(int n) {
	// �ִ� ���� ���� ����
	if (n == board)
		answer++;
	else {
		for (int i = 0; i < board; i++) {
			// �� ��ġ
			col[n] = i;
			// ���� �� ���� �� �ֳ� Ȯ��
			if (prunning(n)) {
				DFS(n + 1);
			}
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

