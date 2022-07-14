#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int N, M, R;

// ��������Ʈ
vector<vector<int>> list(100001);
// �湮���ο� ī����
vector<int> visit(100001, 0);
int idx = 1;

// ���̿켱Ž��
void DFS(int R) {
	visit[R] = idx++;

	for (auto l : list[R]) {
		if (visit[l] != 0)
			continue;

		DFS(l);
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
	// ������������
	for (int i = 0; i <= N; i++)
		sort(list[i].begin(), list[i].end(), greater<>());

	DFS(R);
	
	// ���
	for (int i = 1; i <= N; i++) 
		cout << visit[i] << "\n";

	return 0;
}


