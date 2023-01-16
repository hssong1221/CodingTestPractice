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

// 인접리스트
vector<vector<int>> alist(1001);
// 큐
queue<int> q;

// 노드 방문 여부
vector<int> dvisit(1001, 0);
vector<int> bvisit(1001, 0);

void DFS(int start) {
	dvisit[start] = 1;
	// 방문된 점 출력 
	cout << start << " ";
	for (auto a : alist[start]) {
		// 방문 여부 확인
		if (dvisit[a] != 0)
			continue;

		// visit확인해서 안간데 찾아가기
		DFS(a);
	}
}

void BFS(int start) {
	bvisit[start] = 1;
	q.push(start);	// 큐에 갈 노드 저장

	// 방문된 점 출력
	cout << start << " ";

	while (!q.empty()) {
		int temp = q.front();
		q.pop();
		// 큐 앞에서 꺼낸 숫자부터 방문
		for (auto a : alist[temp]) {
			if (bvisit[a] == 0) {
				bvisit[a] = 1;
				q.push(a);
				// 방문된 점 출력
				cout << a << " ";
			}
		}
	}
}

int main(void) {
	// 입력
	int N, M, R;
	cin >> N >> M >> R;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		// 인접리스트 채우기(간선 여부)
		alist[a].push_back(b);
		alist[b].push_back(a);
	}
	// 작은 노드 부터 방문 하니까 정렬 해야함
	for (int i = 0; i <= N; i++)
		sort(alist[i].begin(), alist[i].end());

	DFS(R);
	cout << "\n";
	BFS(R);

	return 0;
}
