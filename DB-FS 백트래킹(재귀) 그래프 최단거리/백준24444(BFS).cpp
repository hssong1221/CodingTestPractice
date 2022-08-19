#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


int N, M, R;

// 인접리스트
vector<vector<int>> list(100001);
// 방문여부와 카운팅
vector<int> visit(100001, 0);
int idx = 1;
// 큐
queue<int> q;

// 너비우선탐색
void BFS(int R) {
	visit[R] = idx++;
	q.push(R);

	while (!q.empty()) {
		int temp = q.front();
		q.pop();

		for (auto l : list[temp]) {
			if (visit[l] == 0) {
				visit[l] = idx++;
				q.push(l);
			}
		}
	}
}

int main() {
	//입력
	cin >> N >> M >> R;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;

		//인접리스트
		list[a].push_back(b);
		list[b].push_back(a);
	}
	// 정렬
	for (int i = 0; i <= N; i++)
		sort(list[i].begin(), list[i].end());

	BFS(R);

	// 출력
	for (int i = 1; i <= N; i++)
		cout << visit[i] << "\n";

	return 0;
}