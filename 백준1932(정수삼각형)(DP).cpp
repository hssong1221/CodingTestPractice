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
	// �Է�
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

	// ���� �ؿ��� ���� ���鼭 �� �߿� ū ���� �����ͼ� ���Ѵ�. 
	vector<vector<int>> ans(n + 1, vector<int>(n + 1, 0));
	for (int i = 1; i <= n; i++) {
		for (int k = 0; k < i + 1; k++) {
			// ���� ���̶�� ���� �ʿ� x
			if(k - 1 < 0)
				ans[i][k] = ans[i - 1][k] + tri[i - 1][k];
			// ������ �� �϶� ���Ͱ� ��ĭ ������ �־ 0�̶� max()�ϴϱ� ��� ����
			else
				ans[i][k] = max(ans[i - 1][k], ans[i - 1][k - 1]) + tri[i - 1][k];
		}
	}

	// ���ٿ� ���� ū ���� ����
	cout << *max_element(ans[n].begin(), ans[n].end());
	return 0;
}
