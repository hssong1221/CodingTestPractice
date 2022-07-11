#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

vector<int> v(1001);
int main() {
	int answer = 0;
	// 입력
	cin >> n;
	for (int i = 0; i < n; i++) {
		int L, H;
		cin >> L >> H;
		v[L] = H;
	}

	//왼쪽부터 확인
	int max = 0;
	int temp = 0;
	for (int i = 0; i < v.size(); i++) {
		if (max <= v[i]) {
			// 지금까지 모은거 더하기
			answer += temp;
			temp = 0;
			//최댓값
			max = v[i];
			// 현재 면적
			temp += max;
		}
		else 
			temp += max;
	}
	//오른쪽 확인
	max = 0;
	temp = 0;
	for (int i = v.size() - 1; 0 < i; i--) {
		if (max < v[i]) {
			// 지금까지 모은거 더하기
			answer += temp;
			temp = 0;
			//최댓값
			max = v[i];
			// 현재 면적
			temp += max;
		}
		else
			temp += max;
	}

	//마지막으로 제일 높은 기둥 더하기
	answer += max;

	cout << answer;
	return 0;
}
