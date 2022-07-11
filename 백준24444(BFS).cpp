#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


int N, M, R;

// ��������Ʈ
vector<vector<int>> list(100001);
// �湮���ο� ī����
vector<int> visit(100001, 0);
int idx = 1;
// ť
queue<int> q;

// �ʺ�켱Ž��
void BFS(int R) {
	visit[R] = idx++;
	q.push(R);

	while (!q.empty()) {
		int temp = q.front();
		q.pop();

		for (auto l : list[temp]) {
			if (visit[l] == 0) {
				visit[l] = idx++;
				q.push(l);
			}
		}
	}
}

int main() {
	//�Է�
	cin >> N >> M >> R;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;

		//��������Ʈ
		list[a].push_back(b);
		list[b].push_back(a);
	}
	// ����
	for (int i = 0; i <= N; i++)
		sort(list[i].begin(), list[i].end());

	BFS(R);

	// ���
	for (int i = 1; i <= N; i++)
		cout << visit[i] << "\n";

	return 0;
}