#include <iostream>
#include <vector>

using namespace std;

// (인덱스 - 행, 값 - 열)
vector<int> col(16, 0);
// 체스판 크기
int board;
// 정답
int answer = 0;

// 쓸모없는 검사 쳐내기
bool prunning(int n) {
	for (int i = 0; i < n; i++) {
		// 같은 라인에 있고 대각선이라면 거르기
		if (col[n] == col[i] || abs(col[n] - col[i]) == abs(n - i))
			return false;
	}
	return true;
}

void DFS(int n) {
	// 최대 퀸의 갯수 도달
	if (n == board)
		answer++;
	else {
		for (int i = 0; i < board; i++) {
			// 퀸 배치
			col[n] = i;
			// 다음 퀸 놓을 수 있나 확인
			if (prunning(n)) {
				DFS(n + 1);
			}
		}
	}
}



int main() {
	// 입력
	cin >> board;
	// 퀸 -  가로 세로 대각선 금지 따라서 배치 가능한 최대 퀸의 개수는 보드 크기와 같음
	// 같은 행에다가 놓을 수 없으므로 다음 행에서 올수 있는 곳만 판단하면 된다
	DFS(0);

	cout << answer;
	return 0;
}

