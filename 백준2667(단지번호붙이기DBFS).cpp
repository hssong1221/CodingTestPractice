#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// ����
vector<vector<int>> matrix(26, vector<int>(26, 0));
// �湮����
vector<vector<int>> visit(26, vector<int>(26, 0));
// ť
queue<pair<int, int>> q;
// �� ����
int idx = 1;
//����
vector<int> ans;

int N;

//�����¿�
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,-1,1 };

void BFS(int x, int y) {
	visit[x][y] = 1;
	q.emplace(x, y);

	while (!q.empty()) {
		int tx = q.front().first;
		int ty = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = tx + dx[i];
			int ny = ty + dy[i];

			if (0 <= nx && nx < N && 0 <= ny && ny < N) { // ��������
				if (matrix[nx][ny] == 1 && visit[nx][ny] == 0) { // ���̰� ������ ���� ��
					visit[nx][ny] = 1;
					idx++;
					q.emplace(nx, ny);
				}
			}
		}
	}
	ans.push_back(idx);
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int k = 0; k < N; k++) {
			matrix[i][k] = s[k] - 48;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (matrix[i][j] == 1 && visit[i][j] == 0) {
				idx = 1;
				BFS(i, j);
			}
		}
	}

	//���
	cout << ans.size() << "\n";
	sort(ans.begin(), ans.end());
	for (auto a : ans) {
		cout << a << "\n";
	}

	return 0;
}

