#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
	//입력
	stack<int> s;
	int N;
	cin >> N;

	// 정답용
	vector<int> ans(1000000, -1);
	// 자신 오른쪽 몇번째 만에 오큰수가 나오나
	vector<int> list(1000000, 0);
	int cnt = 0;

	for (int i = 0; i < N; i++) {
		int a = 0;
		cin >> a;
		
		// 첫번째 숫자 입력
		if (i == 0) {
			list[i] = a;
		}
		else if (i != 0) {
			// 스택 top 보다 현재 넣는 값이 크면 오큰수임 
			if (s.top() < a) {
				// 밀린 개수 만큼 한번에 추가
				for (int k = 0; k < cnt + 1; k++) {
					// 밀렸던 숫자들보다 커야 오큰수
					if(list[i - cnt + k - 1] < a)
						ans[i - cnt + k ] = a;
				}
				cnt = 0;
			}
			// 작다면 밀린 갯수랑 현재 숫자 측정
			else {
				list[i] = a;
				cnt++;
			}
		}
		s.push(a);
	}
	// 마지막은 -1
	ans[N] = -1;

	for (int i = 1; i <= N; i++)
		cout << ans[i] << " ";
	return 0;
}
