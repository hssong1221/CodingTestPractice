#include <vector>
#include <iostream>
#include <limits.h>

using namespace std;

// �ɷ�ġ ǥ
vector<vector<int>> v(21, vector<int>(21, 0));
// �湮 ����
vector<int> visit(21, 0);

// �ο���
int n = 0;

// �� �ɷ�ġ
int team1 = 0;
int team2 = 0;

// �ּڰ�
int MIN = INT_MAX;

void DFS(int count, int num) {
	// ���� ���� ���� �ɷ�ġ ���
	if (n / 2 == count) {
		// �� �ɷ�ġ
		team1 = 0;
		team2 = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				// ������ �϶�
				if (visit[i] == 1 && visit[j] == 1)
					team1 += v[i][j];
				// �Ѵ� �ٸ����϶�
				if (visit[i] == 0 && visit[j] == 0)
					team2 += v[i][j];
			}
		}

		if (abs(team1 - team2) < MIN)
			MIN = abs(team1 - team2);

		return;
	}

	// �Ѿ�� ���ں��� ���
	for (int i = num; i < n; i++) {
		if (visit[i] == 0) {
			visit[i] = 1;
			// ���� + 1, �ڱ��ڽ� �ڷθ� ���
			DFS(count + 1, i + 1);
			// ��Ʈ��ŷ�� ���ؼ� �ٽ� �ʱ�ȭ
			visit[i] = 0;
		}
	}
}

int main() {
	//�Է�
	cin >> n;

	// ������İ� �����ϰ� �Է¹���
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> v[i][j];
		}
	}

	DFS(0, 1);

	// ���
	cout << MIN ;
	return 0;
}

