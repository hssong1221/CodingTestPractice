#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int N;
// 숫자
vector<int> v;

//+-*/
vector<int> visit;

//결과 리스트
vector<int> rlist;


void DFS(int idx, int result) {
	// 모든 결과값 저장
	if (idx == N) {
		rlist.push_back(result);
		return;
	}

	// 연산자 순서대로 한번씩 방문
	if (visit[0] != 0) { // +
		visit[0]--;
		DFS(idx + 1, result + v[idx]);
		visit[0]++;	// 방문 했으면 다음번을 위해 다시 초기화
	}
	if (visit[1] != 0) { // -
		visit[1]--;
		DFS(idx + 1, result - v[idx]);
		visit[1]++;
	}
	if (visit[2] != 0) { // *
		visit[2]--;
		DFS(idx + 1, result * v[idx]);
		visit[2]++;
	}
	if (visit[3] != 0) { // /
		visit[3]--;
		DFS(idx + 1, result / v[idx]);
		visit[3]++;
	}
}

int main() {
	// 입력
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}
	for (int i = 0; i < 4; i++) {
		int a;
		cin >> a;
		visit.push_back(a);
	}


	DFS(1, v[0]);

	// 정렬해서 앞뒤로 출력
	sort(rlist.begin(), rlist.end());
	cout << rlist.back() << "\n" << rlist.front();

	return 0;
}


