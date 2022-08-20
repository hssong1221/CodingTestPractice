// 누적 합
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	// 빠른 입출력을 위함
	/*ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);*/
	// 입력
	string S;
	cin >> S;
	
	// a - z 까지 누적합 구간별(0부터 S.length까지)로 각각  구하기
	vector<vector<int>> psum(200001, vector<int>(26, 0));

	for (int i = 0; i < S.length(); i++) {
		int temp = S[i] - 97;
		psum[i][temp]++;
		if (i == 0)
			continue;

		for (int k = 0; k < 26; k++) { 
			psum[i][k] += psum[i - 1][k];
		}
	}

	char a;
	int l, r;
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		//입력
		cin >> a;
		cin >> l >> r;

		// r까지 누적합에서 l-1 누적합 빼기
		int idx_a = a - 97;
		int result = 0;
		if(l == 0)
			result = psum[r][idx_a] ;
		else
			result = psum[r][idx_a] - psum[l - 1][idx_a];

		cout << result << "\n";
	}
	
	return 0;
}