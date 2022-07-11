// 백준 1260
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, V;

//인접 행렬
vector<vector<int>> matrix(1001, vector<int>(1001, 0));

//인접리스트
vector<vector<int>> list(1001); // 메모리 초과나서 따로 쓸 수가 없다
queue<int> q;

// 방문 리스트
vector<bool> visit(1001, false);

void DFS(int start) {
	visit[start] = true;
	//출력
	cout << start << " ";
	for (int i = 1; i <= N; i++) {
		if (matrix[start][i] == 1 && visit[i] == 0)
			DFS(i);
	}
}

void BFS(int start) {
	visit[start] = true;
	q.push(start);
	//출력
	cout << start << " ";

	while (!q.empty()) {
		int n = q.front();
		q.pop();

		/*for (int i = 1; i <= N; i++) {
			if (matrix[n][i] == 1 && visit[i] == 0) {
				visit[i] = true;
				q.push(i);
				//출력
				cout << i << " ";
			}
		}*/
		for (int i = 0; i < list[n].size(); i++) {
			int next = list[n][i];
			if (!visit[next]) {
				visit[next] = true;
				q.push(next);
				//출력
				cout << next << " ";
			}
		}
	}
}


int main() {
	//입력
	cin >> N >> M >> V;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		// 인접행렬
		matrix[a][b] = 1;
		matrix[b][a] = 1;
		//인접 리스트
		list[a].push_back(b);
		list[b].push_back(a);
	}

	DFS(V);
	cout << endl;
	
	// BFS - 인접 리스트 후 정렬
	for (int i = 0; i < list.size(); i++)
		sort(list[i].begin(), list[i].end());

	// 방문리스트 초기화
	for (int i = 0; i <= N; i++)
		visit[i] = 0;
	BFS(V);

	return 0;
}

