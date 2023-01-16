#include <string>
#include <vector>
#include <iostream>
#include <climits>
#include <map>
#include <sstream>
#include <set>
#include <algorithm>
#include <bitset>
#include <deque>
#include <unordered_map>
#include <queue>

//빠른 입출력
/*std::ios_base::sync_with_stdio(false);
std::cin.tie(NULL);*/

using namespace std;

// 배추밭
vector<vector<int>> field(51, vector<int>(51, 0));
// 노드 방문 여부
vector<vector<int>> visit(51, vector<int>(51, 0));
// 큐
queue<pair<int, int>> q;
// 배추 뭉탱이 수
int cnt = 0;
// 상하좌우
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,-1,1 };
// 좌표크기
int M, N , K;


void BFS(int x, int y) {
	visit[x][y] = 1;
	q.emplace(x, y);

	while (!q.empty()) {
		int tx = q.front().first;
		int ty = q.front().second;
		q.pop();
		// 좌표에서 상하좌우 확인
		for (int i = 0; i < 4; i++) {
			int nx = tx + dx[i];
			int ny = ty + dy[i];

			// 밭 범위 (상하좌우 확인 할 때 좌표 안쪽만 확인)
			if (0 <= nx && nx < M && 0 <= ny && ny < N) { 
				// 배추가 있고 안 가본곳
				if (field[nx][ny] == 1 && visit[nx][ny] == 0) {
					visit[nx][ny] = 1;
					q.emplace(nx, ny);
				}
			}
		}
	}
	// 한뭉탱이 처리 끝
	cnt++;
}

int main(void) {
	// 입력
	int t;
	cin >> t;
	for (int a = 0; a < t; a++) {
		cin >> M >> N >> K;
		for (int i = 0; i < K; i++) {
			int a, b;
			cin >> a >> b;
			field[a][b] = 1;
		}

		// BFS
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				// 배추가 있고 방문 한적이 없는 좌표를 찾아 시작
				if (field[i][j] == 1 && visit[i][j] == 0) {
					BFS(i, j);
				}
			}
		}

		// 지렁이 출력
		cout << cnt << "\n";

		// 초기화
		q = queue<pair<int, int>>();
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				field[i][j] = 0;
				visit[i][j] = 0;
				cnt = 0;
			}
		}
	}

	return 0;
}
