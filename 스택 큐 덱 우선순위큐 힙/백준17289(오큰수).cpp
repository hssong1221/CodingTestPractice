#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
	//입력
	
	int N;
	cin >> N;

	// 정답용
	vector<int> ans(1000000, -1);
	// 저장용
	vector<int> list(1000000, 0);
	// 위치 저장용(뒤에서부터 확인)
	stack<int> s;


	// 입력
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}

	for (int i = 0; i < N; i++) {
		// 스택이 비어있지 않고 마지막 숫자보다 더 큰숫자일 때
		while (!s.empty() && list[s.top()] < list[i]) {
			// 마지막 숫자를 더 큰숫자로 바꾸고 
			// 스택에서 위치를 빼버림 오큰수로 확정이 났기 때문
			ans[s.top()] = list[i];
			s.pop();
		}
		s.push(i);
	}

	for (int i = 0; i < N; i++)
		cout << ans[i] << " ";

	return 0;
}
