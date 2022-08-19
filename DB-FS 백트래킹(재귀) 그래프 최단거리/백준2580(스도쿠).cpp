#include <iostream>
#include <vector>

using namespace std;

//스도쿠
vector<vector<int>> v(9, vector<int>(9, 0));
// 0 위치
vector<pair<int, int>> pos;
// 0개수
int zero = 0;
// 완성 플래그
bool flag = false;

void DFS(int idx);
bool Pruning(pair<int, int> xy);

int main() {
	// 입력
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> v[i][j];
			// 0 위치와 개수
			if (v[i][j] == 0) {
				zero++;
				pos.emplace_back(i, j);
			}
		}
	}
	DFS(0);
	// 출력
	cout << endl;
	for (auto &a : v) {
		for (auto b : a)
			cout << b << " ";
		cout << "\n";
	}
	return 0;
}

void DFS(int idx) {
	// 모든 숫자를 찾았을 때
	if (idx == zero) {
		flag = true;
		return;
	}
	// 0에다가 숫자 1-9 넣어보기
	for (int i = 1; i <= 9 ; i++) {
		v[pos[idx].first][pos[idx].second] = i;

		//적절한 숫자라면 다음 0으로
		if (Pruning(pos[idx])) {
			DFS(idx + 1);
		}
		//스도쿠 완성
		if (flag)
			return;
	}
	// 1-9전부 아니라면 다시 뒤로
	v[pos[idx].first][pos[idx].second] = 0;
	return;
}

// 적절한지 확인(가로 세로 3*3 확인)
bool Pruning(pair<int, int> xy) {
	for (int i = 0; i < 9; i++) {
		// 가로 확인(값이 같고 위치는 다를 때)
		if (v[xy.first][xy.second] == v[xy.first][i] && xy.second != i)
			return false;
		// 세로 확인(값이 같고 위치는 다를 때)
		if (v[xy.first][xy.second] == v[i][xy.second] && xy.first != i)
			return false;
	}

	//본인 구역 3*3 확인
	int dist_x = xy.first / 3;
	int dist_y = xy.second / 3;
	for (int j = dist_x * 3; j < dist_x * 3 + 3; j++) {
		for (int k = dist_y * 3; k < dist_y * 3 + 3; k++) {
			// 값이 같고 위치는 다를 떄
			if (v[xy.first][xy.second] == v[j][k] && xy.first != j && xy.second != k)
				return false;
		}
	}
	return true;
}