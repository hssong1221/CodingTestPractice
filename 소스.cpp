#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
	//입력
	stack<int> s;
	int N;
	cin >> N;

	// 자신 오른쪽 몇번째 만에 오큰수가 나오나
	vector<pair<int, bool>> list(1000000, { 0, false });
	// 정답용
	vector<int> ans(1000001, -1);
	// 최대값 판별
	int max = 0;
	//
	int idx = 0;

	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;

		list[i].first = a;
		// 스택top보다 옆 숫자가 클 때 오큰수
		if (i != 0) {
			if (s.top() < a) {
				// 대기열
				for (int k = idx; k < i + 1; k++) {
					if (list[k].first < a) {
						ans[k] = a;
					}
				}
				idx = i;
			}
			// 작다면 대기열로 들어감
			else {
				idx = i;
			}
		}

		s.push(a);
	}

	// 마지막은 -1
	ans[N] = -1;

	for (int i = 0; i <= N; i++)
		cout << ans[i] << " ";

	return 0;
}
