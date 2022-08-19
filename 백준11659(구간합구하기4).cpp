#include <iostream>
#include <stdio.h>
#include <vector>

#pragma warning(disable : 6031)
#pragma warning(disable : 4996)

using namespace std;

int main() {
	// 빠른 입출력을 위함
	/*ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);*/

	vector<int> v;
	vector<int> prefixsum;
	//입력
	int N = 0;
	int M = 0;
	//cin >> N >> M;
	scanf("%d %d", &N, &M);
	int temp = 0;
	int n = 0;
	for (int i = 0; i < N; i++) {
		//cin >> n;
		scanf("%d", &n);
		temp += n;
		prefixsum.push_back(temp);
	}

	int answer = 0;
	int i, j;
	// 출력
	for (int k = 0; k < M; k++) {
		//cin >> i >> j;
		scanf("%d %d", &i, &j);
		
		if(i == 1)
			answer = prefixsum[j - 1];
		else 
			answer = prefixsum[j - 1] - prefixsum[i - 2];

		//cout << answer << "\n";
		printf("%d\n", answer);
	}
	return 0;
}