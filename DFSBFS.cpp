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
#include <queue>

//���� �����
/*std::ios_base::sync_with_stdio(false);
std::cin.tie(NULL);*/

using namespace std;

// ��������Ʈ
vector<vector<int>> alist(1001);
// ť
queue<int> q;

// ��� �湮 ����
vector<int> dvisit(1001, 0);
vector<int> bvisit(1001, 0);

void DFS(int start) {
	dvisit[start] = 1;
	// �湮�� �� ��� 
	cout << start << " ";
	for (auto a : alist[start]) {
		// �湮 ���� Ȯ��
		if (dvisit[a] != 0)
			continue;

		// visitȮ���ؼ� �Ȱ��� ã�ư���
		DFS(a);
	}
}

void BFS(int start) {
	bvisit[start] = 1;
	q.push(start);	// ť�� �� ��� ����

	// �湮�� �� ���
	cout << start << " ";

	while (!q.empty()) {
		int temp = q.front();
		q.pop();
		// ť �տ��� ���� ���ں��� �湮
		for (auto a : alist[temp]) {
			if (bvisit[a] == 0) {
				bvisit[a] = 1;
				q.push(a);
				// �湮�� �� ���
				cout << a << " ";
			}
		}
	}
}

int main(void) {
	// �Է�
	int N, M, R;
	cin >> N >> M >> R;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		// ��������Ʈ ä���(���� ����)
		alist[a].push_back(b);
		alist[b].push_back(a);
	}
	// ���� ��� ���� �湮 �ϴϱ� ���� �ؾ���
	for (int i = 0; i <= N; i++)
		sort(alist[i].begin(), alist[i].end());

	DFS(R);
	cout << "\n";
	BFS(R);

	return 0;
}
