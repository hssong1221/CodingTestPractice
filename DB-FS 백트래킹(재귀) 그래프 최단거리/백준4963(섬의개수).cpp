#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

//지도크기
int w, h;
// 지도
vector<vector<int>> map(51, vector<int>(51, 0));
// 방문
vector<vector<int>> visit(51, vector<int>(51, 0));

//큐
queue<pair<int, int>> q;

// 위쪽부터 한바퀴
int dx[8] = { 0,1,1,1,0,-1,-1,-1 };
int dy[8] = { 1,1,0,-1,-1,-1,0,1 };
// 섬개수
int idx = 0;

void BFS(int x, int y) {
	visit[x][y] = 1;
	q.emplace(x, y);

	idx++;

	while (!q.empty()) {
		int tx = q.front().first;
		int ty = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++) {
			int nx = tx + dx[i];
			int ny = ty + dy[i];

			if (0 <= nx && nx < h && 0 <= ny && ny < w) {
				if (visit[nx][ny] == 0 && map[nx][ny] == 1) {
					visit[nx][ny] = 1;
					q.emplace(nx, ny);
				}
			}
		}
	}
}

int main() {
	while (true) {
		// 입력
		cin >> w >> h;
		if (w == 0 && h == 0)
			break;

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				int a;
				cin >> a;
				map[i][j] = a;
			}
		}

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if(map[i][j] == 1 && visit[i][j] == 0)
					BFS(i, j);
			}
		}

		//출력
		cout << idx << endl;
		//reset;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				map[i][j] = 0;
				visit[i][j] = 0;
			}
		}
		idx = 0;
		q = queue<pair<int, int>>();
	}
	return 0;
}

