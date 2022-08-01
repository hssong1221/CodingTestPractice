#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

int main() {
	int answer = 0;
	// 입력
	int A, B;
	cin >> A >> B;
	set<int> sA;
	set<int> sB;
	// a집합
	for (int i = 0; i < A; i++) {
		int temp;
		cin >> temp;
		sA.insert(temp);
	}
	// b집합
	for (int i = 0; i < B; i++) {
		int temp;
		cin >> temp;
		sB.insert(temp);
	}

	// a-b
	auto iter = sB.begin();
	int a = 0;
	for (int i = 0; i < sB.size(); i++) {
		auto k = sA.find(*iter);
		if (k != sA.end())
			a++;
		iter++;
	}
	answer += sA.size() - a;

	//b-a
	iter = sA.begin();
	int b = 0;
	for (int i = 0; i < sA.size(); i++) {
		auto k = sB.find(*iter);
		if (k != sB.end())
			b++;
		iter++;
	}
	answer += sB.size() - b;

	cout << answer;
	return 0;
}