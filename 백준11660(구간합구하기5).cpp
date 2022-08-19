//누적합 prefix sum
#include <iostream>
#include <vector>

using namespace std;


int main() {
	// 빠른 입출력을 위함
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 누적합
	vector<vector<int>> grid(1025, vector<int>(1025, 0));

	// 입력
	int N, M;
	cin >> N >> M;

	// 누적합
	int temp;
	int n;
	for (int i = 1; i <= N; i++) {
		temp = 0;
		for (int j = 1; j <= N; j++) {
			cin >> n;
			temp += n;
			grid[i][j] = grid[i - 1][j] + temp;
		}
	}


	for (int i = 0; i < M; i++) {
		// 입력
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		int answer = 0;
		// 2차원 누적합 구하는 공식
		answer = grid[x2][y2] - grid[x1 - 1][y2] - grid[x2][y1 - 1] + grid[x1 - 1][y1 - 1];

		cout << answer << "\n";
	}

	return 0;
}