#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// 미로
vector<vector<int>> matrix(101, vector<int>(101, 0));
// 방문여부
vector<vector<int>> visit(101, vector<int>(101, 0));
// 최소거리
vector<vector<int>> len(101, vector<int>(101, 0));
// 큐
queue<pair<int, int>> q;

int N, M;

//상하좌우
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,-1,1 };

void BFS(int x, int y) {
	visit[x][y] = 1;
	q.emplace(x, y);

	while (!q.empty()) {
		int tx = q.front().first;
		int ty = q.front().second;
		q.pop();

		//상하좌우
		for (int i = 0; i < 4; i++) {
			int nx = tx + dx[i];
			int ny = ty + dy[i];

			// 미로 범위
			if (0 <= nx && nx < N && 0 <= ny && ny < M) {
				if (matrix[nx][ny] == 1 && visit[nx][ny] == 0) {
					visit[nx][ny] = 1;
					len[nx][ny] = len[tx][ty] + 1;
					q.emplace(nx, ny);
				}
			}

		}
	}
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int k = 0; k < M; k++) {
			matrix[i][k] = s[k] - 48;
		}
	}
	BFS(0, 0);

	cout << len[N - 1][M - 1] + 1;
	return 0;
}

