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

//���� �����
/*std::ios_base::sync_with_stdio(false);
std::cin.tie(NULL);*/

using namespace std;

int main(void) {
	vector<int> r;
	vector<int> g;
	vector<int> b;
	int n;

	// �Է�
	cin >> n;
	for (int i = 0; i < n; i++) {
		int rr, gg, bb;
		cin >> rr >> gg >> bb;
		r.push_back(rr);
		g.push_back(gg);
		b.push_back(bb);
	}

	// ��� �������� ��ĭ �� �з��� n + 1 
	vector<vector<int>> ans(n + 1, vector<int>(n, 0)); 
	// rgb�� ��ġ�� �ʰ� �ּҰ��� ã�´�.
	for (int i = 1; i <= n; i++) {
		ans[i][0] = min(ans[i - 1][1], ans[i - 1][2]) + r[i - 1]; // R�� ���� �� ������ �� ��
		ans[i][1] = min(ans[i - 1][0], ans[i - 1][2]) + g[i - 1]; // G�� ���� �� ������ �� ��
		ans[i][2] = min(ans[i - 1][0], ans[i - 1][1]) + b[i - 1]; // B�� ���� �� ������ �� ��
	}

	int answer = min(min(ans[n][0], ans[n][1]), ans[n][2]); // ��ü ����� �� ���� �ּҰ�
	cout << answer;

	return 0;
}
