// 누적합 투포인터
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	vector<int> psum(100001, 0); // 누적 합
	vector<int> tsum; // 온도 합
	// 입력
	int N, K;
	cin >> N >> K;

	//누적합
	int n = 0;
	int temp = 0;
	for (int i = 1; i <= N; i++) {
		cin >> n;
		temp += n;
		psum[i] = temp;
	}

	// 누적합으로 부분합 계산
	int sum = 0;
	for (int i = 0; i <= N - K; i++) {
		sum = psum[i + K] - psum[i];
		tsum.push_back(sum);
	}


	// 내림차순 맨 앞 제일큼
	sort(tsum.begin(), tsum.end(), greater<>());

	int answer = tsum[0];
	cout << answer;

	return 0;
}