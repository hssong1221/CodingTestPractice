//2003 수들의 합

#include <iostream>
#include <vector>

using namespace std;

int main() {
	int num;
	int sum;
	int n;
	int answer =0;

	cin >> num;
	cin >> sum;

	vector<int> v;
	for (int i = 0; i < num; i++) {
		cin >> n;
		v.push_back(n);
	}

	auto start = v.begin();
	auto end = v.begin();

	int temp = 0;
	while (true) {
		if (start == v.end())
			break;

		temp = 0;

		for (auto it = start; it != end; it++) {
			temp += *it;
		}

		if (temp < sum && end != v.end()) {
			end++;
		}
		else {
			if (temp == sum)
				answer++;
			
			start++;
		}
	}
	cout << answer;
	return 0;
}