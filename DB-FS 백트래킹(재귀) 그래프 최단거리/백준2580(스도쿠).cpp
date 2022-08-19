#include <iostream>
#include <vector>

using namespace std;

//������
vector<vector<int>> v(9, vector<int>(9, 0));
// 0 ��ġ
vector<pair<int, int>> pos;
// 0����
int zero = 0;
// �ϼ� �÷���
bool flag = false;

void DFS(int idx);
bool Pruning(pair<int, int> xy);

int main() {
	// �Է�
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> v[i][j];
			// 0 ��ġ�� ����
			if (v[i][j] == 0) {
				zero++;
				pos.emplace_back(i, j);
			}
		}
	}
	DFS(0);
	// ���
	cout << endl;
	for (auto &a : v) {
		for (auto b : a)
			cout << b << " ";
		cout << "\n";
	}
	return 0;
}

void DFS(int idx) {
	// ��� ���ڸ� ã���� ��
	if (idx == zero) {
		flag = true;
		return;
	}
	// 0���ٰ� ���� 1-9 �־��
	for (int i = 1; i <= 9 ; i++) {
		v[pos[idx].first][pos[idx].second] = i;

		//������ ���ڶ�� ���� 0����
		if (Pruning(pos[idx])) {
			DFS(idx + 1);
		}
		//������ �ϼ�
		if (flag)
			return;
	}
	// 1-9���� �ƴ϶�� �ٽ� �ڷ�
	v[pos[idx].first][pos[idx].second] = 0;
	return;
}

// �������� Ȯ��(���� ���� 3*3 Ȯ��)
bool Pruning(pair<int, int> xy) {
	for (int i = 0; i < 9; i++) {
		// ���� Ȯ��(���� ���� ��ġ�� �ٸ� ��)
		if (v[xy.first][xy.second] == v[xy.first][i] && xy.second != i)
			return false;
		// ���� Ȯ��(���� ���� ��ġ�� �ٸ� ��)
		if (v[xy.first][xy.second] == v[i][xy.second] && xy.first != i)
			return false;
	}

	//���� ���� 3*3 Ȯ��
	int dist_x = xy.first / 3;
	int dist_y = xy.second / 3;
	for (int j = dist_x * 3; j < dist_x * 3 + 3; j++) {
		for (int k = dist_y * 3; k < dist_y * 3 + 3; k++) {
			// ���� ���� ��ġ�� �ٸ� ��
			if (v[xy.first][xy.second] == v[j][k] && xy.first != j && xy.second != k)
				return false;
		}
	}
	return true;
}