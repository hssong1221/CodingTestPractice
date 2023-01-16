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

// ���߹�
vector<vector<int>> field(51, vector<int>(51, 0));
// ��� �湮 ����
vector<vector<int>> visit(51, vector<int>(51, 0));
// ť
queue<pair<int, int>> q;
// ���� ������ ��
int cnt = 0;
// �����¿�
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,-1,1 };
// ��ǥũ��
int M, N , K;


void BFS(int x, int y) {
	visit[x][y] = 1;
	q.emplace(x, y);

	while (!q.empty()) {
		int tx = q.front().first;
		int ty = q.front().second;
		q.pop();
		// ��ǥ���� �����¿� Ȯ��
		for (int i = 0; i < 4; i++) {
			int nx = tx + dx[i];
			int ny = ty + dy[i];

			// �� ���� (�����¿� Ȯ�� �� �� ��ǥ ���ʸ� Ȯ��)
			if (0 <= nx && nx < M && 0 <= ny && ny < N) { 
				// ���߰� �ְ� �� ������
				if (field[nx][ny] == 1 && visit[nx][ny] == 0) {
					visit[nx][ny] = 1;
					q.emplace(nx, ny);
				}
			}
		}
	}
	// �ѹ����� ó�� ��
	cnt++;
}

int main(void) {
	// �Է�
	int t;
	cin >> t;
	for (int a = 0; a < t; a++) {
		cin >> M >> N >> K;
		for (int i = 0; i < K; i++) {
			int a, b;
			cin >> a >> b;
			field[a][b] = 1;
		}

		// BFS
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				// ���߰� �ְ� �湮 ������ ���� ��ǥ�� ã�� ����
				if (field[i][j] == 1 && visit[i][j] == 0) {
					BFS(i, j);
				}
			}
		}

		// ������ ���
		cout << cnt << "\n";

		// �ʱ�ȭ
		q = queue<pair<int, int>>();
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				field[i][j] = 0;
				visit[i][j] = 0;
				cnt = 0;
			}
		}
	}

	return 0;
}
