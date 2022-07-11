#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

// 체스판
vector<vector<int>> chess(301, vector<int>(301, 0));
// 확인
vector<vector<int>> visit(301, vector<int>(301, 0));
// 횟수
vector<vector<int>> seq(301, vector<int>(301, 0));
//queue
queue<pair<int, int>> q;

//경우의수
int dx[8] = { 1,2,2,1,-1,-2,-2,-1 };
int dy[8] = { 2,1,-1,-2,-2,-1,1,2 };
// 체스판 크기
int l;

void BFS(int x, int y, int destx, int desty) {
	visit[x][y] = 1;
	q.emplace(x, y);

	while (!q.empty()) {
		int tx = q.front().first;
		int ty = q.front().second;

		if (tx == destx && ty == desty)
			break;

		q.pop();
		

		for (int i = 0; i < 8; i++) {
			int nx = tx + dx[i];
			int ny = ty + dy[i];

			if (0 <= nx && nx < l && 0 <= ny && ny < l) {
				if (visit[nx][ny] == 0) {
					visit[nx][ny] = 1;
					seq[nx][ny] = seq[tx][ty] + 1;
					q.emplace(nx, ny);
				}
			}
		}
	}
}

int main() {
	// 입력
	int test;
	cin >> test;
	for (int i = 0; i < test; i++) {
		cin >> l;
		int a, b;
		int c, d;
		cin >> a >> b;
		cin >> c >> d;

		BFS(a,b,c,d);

		/*for (int n = 0; n < l; n++) {
			for (int m = 0; m < l; m++) {
				cout << seq[n][m] << " ";
			}
			cout << endl;
		}*/

		cout << seq[c][d] << endl;

		// reset
		for (int n = 0; n <= l; n++) {
			for (int m = 0; m <= l; m++) {
				chess[n][m] = 0;
				visit[n][m] = 0;
				seq[n][m] = 0;
			}
		}
		q = queue < pair<int, int>>();
	}
	return 0;
}

