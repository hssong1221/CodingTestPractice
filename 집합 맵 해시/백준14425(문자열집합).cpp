#include <vector>
#include <string>
#include <iostream>
#include <map>

using namespace std;

int main() {
	int answer = 0;
	// 입력
	int N, M;
	cin >> N >> M;
	map<string, int> m;
	for (int i = 0; i < N; i++) {
		string temp = "";
		cin >> temp;
		m[temp] = 1;
	}

	// 검사 리스트
	vector<string> v;
	for (int i = 0; i < M; i++) {
		string temp = "";
		cin >> temp;
		v.push_back(temp);
	}
	// 맵에 있는지 없는지 확인
	for (int i = 0; i < v.size(); i++) {
		// begin()부터 end()까지 확인하다 없으면 end()가서 멈춤
		auto k = m.find(v[i]);
		if (k != m.end())
			answer++;
	}
	
	//출력
	cout << answer;
	return 0;
}