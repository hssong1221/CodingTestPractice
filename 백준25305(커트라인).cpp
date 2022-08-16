#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	//입력
	int N, k;
	cin >> N >> k;

	vector<int> list;
	for (int i = 0; i < N; i++) {
		int x = 0;
		cin >> x;
		list.push_back(x);
	}
	// 내림차순 정렬
	sort(list.begin(), list.end(), greater<>());

	cout << list[k - 1];

	return 0;
}