#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int N, M, R;

// 인접리스트
vector<vector<int>> list(100001);
// 방문여부와 카운팅
vector<int> visit(100001, 0);
int idx = 1;

// 깊이우선탐색
void DFS(int R) {
	visit[R] = idx++;

	for (auto l : list[R]) {
		if (visit[l] != 0)
			continue;

		DFS(l);
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
	// 내림차순정렬
	for (int i = 0; i <= N; i++)
		sort(list[i].begin(), list[i].end(), greater<>());

	DFS(R);
	
	// 출력
	for (int i = 1; i <= N; i++) 
		cout << visit[i] << "\n";

	return 0;
}


