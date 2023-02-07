#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> paper(101, vector<int>(101, 0));

int main() {
	int answer = 0;
	int t;
	cin >> t;

	// 종이 갯수
	for (int i = 0; i < t; i++) {
		//입력
		int x, y;
		cin >> x >> y;

		// 검은 영역 칠하기
		for (int j = x; j < x + 10; j++) {
			for (int k = y; k < y + 10; k++)
				paper[j][k] = 1;
		}
	}

	// 검음 영역 출력
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if(paper[i][j] == 1)
				answer++;
		}
	}
	cout << answer;
	return 0;
}