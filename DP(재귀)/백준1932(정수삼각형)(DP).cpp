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
	vector<vector<int>> tri(n + 1, vector<int>(n + 1, 0));
	for (int i = 0; i < n; i++) {
		for (int k = 0; k <= i; k++) {
			int t;
			cin >> t;
			tri[i][k] = t;
		}
	}

	// 한줄 밑에서 위를 보면서 둘 중에 큰 수를 가져와서 더한다. 
	vector<vector<int>> ans(n + 1, vector<int>(n + 1, 0));
	for (int i = 1; i <= n; i++) {
		for (int k = 0; k < i + 1; k++) {
			// 왼쪽 끝이라면 비교할 필요 x
			if(k - 1 < 0)
				ans[i][k] = ans[i - 1][k] + tri[i - 1][k];
			// 오른쪽 끝 일땐 벡터가 한칸 여유가 있어서 0이랑 max()하니까 상관 없음
			else
				ans[i][k] = max(ans[i - 1][k], ans[i - 1][k - 1]) + tri[i - 1][k];
		}
	}

	// 막줄에 가장 큰 수가 있음
	cout << *max_element(ans[n].begin(), ans[n].end());
	return 0;
}
