#include <string>
#include <vector>
#include <iostream>
#include <climits>
#include <map>
#include <sstream>
#include <set>
#include <algorithm>
#include <bitset>
#include <deque>
#include <unordered_map>

//빠른 입출력
/*std::ios_base::sync_with_stdio(false);
std::cin.tie(NULL);*/

using namespace std;

int main(void) {
	// 입력
	int n;
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		v.push_back(t);
	}

	
	//초기값 설정
	vector<int> temp(n, 0);
	temp[0] = v[0];
	int max = temp[0]; 

	for (int i = 1; i < v.size(); i++) {
		//지금까지 더한 수와 현재 수를 비교 하면 된다.
		temp[i] = temp[i - 1] + v[i];

		// 지금까지 더 했던거보다 더 큰 값이 나오면 바꿔준다.
		if (v[i] > temp[i]) {
			temp[i] = v[i];
		}

		// 최대값을 기억한다
		if (max < temp[i])
			max = temp[i];
	}
	cout << max;
	return 0;
}
