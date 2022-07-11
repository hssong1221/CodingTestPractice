// ���� 1260
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, V;

//���� ���
vector<vector<int>> matrix(1001, vector<int>(1001, 0));

//��������Ʈ
vector<vector<int>> list(1001); // �޸� �ʰ����� ���� �� ���� ����
queue<int> q;

// �湮 ����Ʈ
vector<bool> visit(1001, false);

void DFS(int start) {
	visit[start] = true;
	//���
	cout << start << " ";
	for (int i = 1; i <= N; i++) {
		if (matrix[start][i] == 1 && visit[i] == 0)
			DFS(i);
	}
}

void BFS(int start) {
	visit[start] = true;
	q.push(start);
	//���
	cout << start << " ";

	while (!q.empty()) {
		int n = q.front();
		q.pop();

		/*for (int i = 1; i <= N; i++) {
			if (matrix[n][i] == 1 && visit[i] == 0) {
				visit[i] = true;
				q.push(i);
				//���
				cout << i << " ";
			}
		}*/
		for (int i = 0; i < list[n].size(); i++) {
			int next = list[n][i];
			if (!visit[next]) {
				visit[next] = true;
				q.push(next);
				//���
				cout << next << " ";
			}
		}
	}
}


int main() {
	//�Է�
	cin >> N >> M >> V;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		// �������
		matrix[a][b] = 1;
		matrix[b][a] = 1;
		//���� ����Ʈ
		list[a].push_back(b);
		list[b].push_back(a);
	}

	DFS(V);
	cout << endl;
	
	// BFS - ���� ����Ʈ �� ����
	for (int i = 0; i < list.size(); i++)
		sort(list[i].begin(), list[i].end());

	// �湮����Ʈ �ʱ�ȭ
	for (int i = 0; i <= N; i++)
		visit[i] = 0;
	BFS(V);

	return 0;
}

