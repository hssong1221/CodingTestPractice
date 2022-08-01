#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int N;
// ����
vector<int> v;

//+-*/
vector<int> visit;

//��� ����Ʈ
vector<int> rlist;


void DFS(int idx, int result) {
	// ��� ����� ����
	if (idx == N) {
		rlist.push_back(result);
		return;
	}

	// ������ ������� �ѹ��� �湮
	if (visit[0] != 0) { // +
		visit[0]--;
		DFS(idx + 1, result + v[idx]);
		visit[0]++;	// �湮 ������ �������� ���� �ٽ� �ʱ�ȭ
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
	// �Է�
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

	// �����ؼ� �յڷ� ���
	sort(rlist.begin(), rlist.end());
	cout << rlist.back() << "\n" << rlist.front();

	return 0;
}


