#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int main() {
	// 빠른 입출력을 위함
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	//입력
	int N = 0;
	int M = 0;
	cin >> N >> M;

	// prefix sum
	// 구간합 = ps[k] - ps[i]
	// (ps[k] - ps[i]) % MOD = 0구하기
	// ps[k] % MOD = ps[i] % MOD 성립(같은 나머지)
	// 
	// ps[i] % MOD 하고 같은 나머지 끼리 합하기
	vector<long long> psMOD(1001, 0);
	long long temp = 0;
	long long A = 0;
	for (int i = 0; i < N; i++) {
		cin >> A;
		temp += A;
		psMOD[temp % M]++;
	}

	// 같은 나머지인 것 중에서 2개 뽑는 것 뽑고 (앞이 뒤보다 큰 번호쌍 제외 (1,2) - (2, 1)x )
	// +
	// ps[i] % MOD = 0 인거 개수
	long long answer = 0;
	for (int i = 0; i <= 1000; i++) {
		answer += (psMOD[i] * (psMOD[i] - 1)) / 2;
	}
	// 출력
	cout << answer + psMOD[0];

	return 0;
}