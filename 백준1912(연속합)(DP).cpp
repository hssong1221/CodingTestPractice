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
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		v.push_back(t);
	}

	
	//�ʱⰪ ����
	vector<int> temp(n, 0);
	temp[0] = v[0];
	int max = temp[0]; 

	for (int i = 1; i < v.size(); i++) {
		//���ݱ��� ���� ���� ���� ���� �� �ϸ� �ȴ�.
		temp[i] = temp[i - 1] + v[i];

		// ���ݱ��� �� �ߴ��ź��� �� ū ���� ������ �ٲ��ش�.
		if (v[i] > temp[i]) {
			temp[i] = v[i];
		}

		// �ִ밪�� ����Ѵ�
		if (max < temp[i])
			max = temp[i];
	}
	cout << max;
	return 0;
}
