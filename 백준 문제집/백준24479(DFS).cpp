#include <iostream>
#include <vector>
#include <algorithm>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int N, M, R;
// 인접리스트
vector<vector<int>> list(100001);
// 방문여부
vector<int> visit(100001,0);

int idx = 1;
void DFS(int R) {
	visit[R] = idx++;

	for (auto &l : list[R] ) {
		if (visit[l] != 0) 
			continue;

		DFS(l);
	}
}

int main() {
	// 입력
	fastio;

	cin >> N >> M >> R;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		// 인접리스트
		list[a].push_back(b);
		list[b].push_back(a);
	}
	for (int i = 1; i <= N; i++)
		sort(list[i].begin(), list[i].end());

	DFS(R);

	//출력
	for (int i = 1; i <= N; i++)
		cout << visit[i] << "\n";

	return 0;
}


