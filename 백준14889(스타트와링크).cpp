#include <vector>
#include <iostream>
#include <limits.h>

using namespace std;

// 능력치 표
vector<vector<int>> v(21, vector<int>(21, 0));
// 방문 여부
vector<int> visit(21, 0);

// 인원수
int n = 0;

// 팀 능력치
int team1 = 0;
int team2 = 0;

// 최솟값
int MIN = INT_MAX;

void DFS(int count, int num) {
	// 팀을 전부 고르면 능력치 계산
	if (n / 2 == count) {
		// 팀 능력치
		team1 = 0;
		team2 = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				// 같은팀 일때
				if (visit[i] == 1 && visit[j] == 1)
					team1 += v[i][j];
				// 둘다 다른팀일때
				if (visit[i] == 0 && visit[j] == 0)
					team2 += v[i][j];
			}
		}

		if (abs(team1 - team2) < MIN)
			MIN = abs(team1 - team2);

		return;
	}

	// 넘어온 숫자부터 계산
	for (int i = num; i < n; i++) {
		if (visit[i] == 0) {
			visit[i] = 1;
			// 개수 + 1, 자기자신 뒤로만 계산
			DFS(count + 1, i + 1);
			// 백트래킹을 위해서 다시 초기화
			visit[i] = 0;
		}
	}
}

int main() {
	//입력
	cin >> n;

	// 인접행렬과 유사하게 입력받음
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> v[i][j];
		}
	}

	DFS(0, 1);

	// 출력
	cout << MIN ;
	return 0;
}

