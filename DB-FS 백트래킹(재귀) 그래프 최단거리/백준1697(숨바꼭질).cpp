#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, K;
//�湮����
vector<int> visit(200001, 0);
// ī��Ʈ
vector<int> seq(200001, 0);

//ť
queue<int> q;
void BFS(int start, int dest) {
	visit[start] = 1;
	q.push(start);

	while (!q.empty()) {
		int temp = q.front();

		if (temp == dest) { // �����ϸ� ����
			break;
		}
		q.pop();

		for (int i = 0; i < 3; i++) {
			int next = 0;
			if (i == 0)
				next = temp + 1;
			else if (i == 1)
				next = temp - 1;
			else
				next = temp * 2;

			if (next > 100000 || next < 0 )
				continue;

			if (visit[next] == 0) { // �� ������
				visit[next] = 1;
				seq[next] = seq[temp] + 1; // ���������� ���°���� ����
				q.push(next);
			}
		}
	}
	// BFS�� �ִܰŸ��� ������
	// ���
	cout << seq[K];
}

int main() {
	//�Է�
	cin >> N >> K;

	BFS(N, K);

	return 0;
}

