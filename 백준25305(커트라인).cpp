#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	//�Է�
	int N, k;
	cin >> N >> k;

	vector<int> list;
	for (int i = 0; i < N; i++) {
		int x = 0;
		cin >> x;
		list.push_back(x);
	}
	// �������� ����
	sort(list.begin(), list.end(), greater<>());

	cout << list[k - 1];

	return 0;
}