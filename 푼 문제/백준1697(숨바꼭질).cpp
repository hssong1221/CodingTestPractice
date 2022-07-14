#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, K;
//방문여부
vector<int> visit(200001, 0);
// 카운트
vector<int> seq(200001, 0);

//큐
queue<int> q;
void BFS(int start, int dest) {
	visit[start] = 1;
	q.push(start);

	while (!q.empty()) {
		int temp = q.front();

		if (temp == dest) { // 도착하면 멈춤
			break;
		}
		q.pop();

		for (int i = 0; i < 3; i++) {
			int next = 0;
			if (i == 0)
				next = temp + 1;
			else if (i == 1)
				next = temp - 1;
			else
				next = temp * 2;

			if (next > 100000 || next < 0 )
				continue;

			if (visit[next] == 0) { // 안 가본곳
				visit[next] = 1;
				seq[next] = seq[temp] + 1; // 도착지점이 몇번째인지 저장
				q.push(next);
			}
		}
	}
	// BFS는 최단거리를 보장함
	// 출력
	cout << seq[K];
}

int main() {
	//입력
	cin >> N >> K;

	BFS(N, K);

	return 0;
}

