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
	vector<int> r;
	vector<int> g;
	vector<int> b;
	int n;

	// 입력
	cin >> n;
	for (int i = 0; i < n; i++) {
		int rr, gg, bb;
		cin >> rr >> gg >> bb;
		r.push_back(rr);
		g.push_back(gg);
		b.push_back(bb);
	}

	// 계산 과정에서 한칸 씩 밀려서 n + 1 
	vector<vector<int>> ans(n + 1, vector<int>(n, 0)); 
	// rgb가 겹치지 않게 최소값을 찾는다.
	for (int i = 1; i <= n; i++) {
		ans[i][0] = min(ans[i - 1][1], ans[i - 1][2]) + r[i - 1]; // R을 선택 시 다음에 올 수
		ans[i][1] = min(ans[i - 1][0], ans[i - 1][2]) + g[i - 1]; // G를 선택 시 다음에 올 수
		ans[i][2] = min(ans[i - 1][0], ans[i - 1][1]) + b[i - 1]; // B를 선택 시 다음에 올 수
	}

	int answer = min(min(ans[n][0], ans[n][1]), ans[n][2]); // 전체 경우의 수 에서 최소값
	cout << answer;

	return 0;
}
