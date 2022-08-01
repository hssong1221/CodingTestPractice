#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int M, N;
// ������ ����(�ʹ� ���� ����)
vector<vector<int>> tomato(1001, vector<int>(1001, 0));
// Ȯ��
vector<vector<int>> visit(1001, vector<int>(1001, 0));

//ť
queue<pair<int, int>> q;

//�����¿�
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,-1,1 };

void BFS() {

	while (!q.empty()) {
		int tx = q.front().first;
		int ty = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = tx + dx[i];
			int ny = ty + dy[i];

			if (0 <= nx && nx < N && 0 <= ny && ny < M) { //���� ����
				if (visit[nx][ny] == 0 && tomato[nx][ny] != -1 && tomato[nx][ny] == 0) { // ���� �Ȱ��� ��������̰� ����� �ƴҰ� ������ �丶���϶�
					visit[nx][ny] = 1;
					tomato[nx][ny] = tomato[tx][ty] + 1;
					q.emplace(nx, ny);
				}
			}
		}
	}
}

int main() {
	//input
	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int a;
			cin >> a;
			tomato[i][j] = a;
		}
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (tomato[i][j] == 1) { // �������� �������϶� �̸� ť�� �־����
				q.emplace(i, j);
			}
		}
	}

	BFS();

	int max = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (tomato[i][j] == 0) {	// �� ���� 0�� ������ ��� ������ ���� ��� 
				cout << -1 << "\n";
				return 0;
			}
			// �ִ�
			if (max < tomato[i][j])
				max = tomato[i][j];
		}
	}
	cout << max - 1;
	return 0;
}

