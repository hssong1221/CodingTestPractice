#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// ��
vector<vector<int>> matrix(51, vector<int>(51, 0));
// �湮����
vector<vector<int>> visit(51, vector<int>(51, 0));
// ť
queue<pair<int, int>> q;
// ���ߵ��
int idx = 1;
//����
vector<int> ans;

int C;
int M, N, K;

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

			if (0 <= nx && nx < M && 0 <= ny && ny < N) { // �� ����
				if (matrix[nx][ny] == 1 && visit[nx][ny] == 0) { // ���߰� Ȯ�� ���� ��
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
	//�Է�
	cin >> C;
	for (int c = 0; c < C; c++) {
		cin >> M >> N >> K;
		for (int i = 0; i < K; i++) {
			int a, b;
			cin >> a >> b;
			matrix[a][b] = 1;
		}
		// �Է¿��� �� ���� ���� �ٲ㼭 �ְ� ����
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (matrix[i][j] == 1 && visit[i][j] == 0) {
					idx = 1;
					BFS(i, j);
				}
			}
		}
		
		//���
		cout << ans.size() << "\n";

		//reset;
		for (int i = 0; i < 51; i++) {
			for (int j = 0; j < 51; j++) {
				matrix[i][j] = 0;
				visit[i][j] = 0;
			}
		}
		ans.clear();
	}

	return 0;
}

