#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> paper(101, vector<int>(101, 0));

int main() {
	int answer = 0;
	int t;
	cin >> t;

	// ���� ����
	for (int i = 0; i < t; i++) {
		//�Է�
		int x, y;
		cin >> x >> y;

		// ���� ���� ĥ�ϱ�
		for (int j = x; j < x + 10; j++) {
			for (int k = y; k < y + 10; k++)
				paper[j][k] = 1;
		}
	}

	// ���� ���� ���
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if(paper[i][j] == 1)
				answer++;
		}
	}
	cout << answer;
	return 0;
}