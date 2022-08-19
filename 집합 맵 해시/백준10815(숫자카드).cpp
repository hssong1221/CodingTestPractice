#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int main() {
	// 입력
	int N, M;
	cin >> N;
	map<int, int> m;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		m[temp] = 1;
	}
	// 검사 리스트
	cin >> M;
	vector<int> v;
	vector<int> answer;
	for (int i = 0; i < M; i++) {
		int temp;
		cin >> temp;
		v.push_back(temp);
		answer.push_back(0);
	}
	// 맵에 있는지 없는지 확인
	for (int i = 0; i < v.size(); i++) {
		if (m[v[i]] == 1) {
			answer[i] = 1;
		}
	}

	//출력
	for (auto a : answer)
		cout << a << " ";
	return 0;
}