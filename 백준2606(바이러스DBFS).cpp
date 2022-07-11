#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

map<string, vector<int>> m;

using namespace std;

int com;
int e;
// ��������Ʈ
vector<vector<int>> list(101);
// �湮����
vector<int> v(101, 0);

// ����
int idx = 0;
// ���� �켱 Ž��
void DFS(int start) {
	v[start] = 1;

	for (auto l : list[start]) {
		if (v[l] == 0) {
			idx++;
			DFS(l);
		}
	}
}

queue<int> q;
int idx2 = 0;
void BFS(int start) {
	v[start] = 1;
	q.push(start);

	while (!q.empty()){
		int temp = q.front();
		q.pop();

		for (auto l : list[temp]) {
			if (v[l] == 0) {
				v[l] = 1;
				q.push(l);
				idx2++;
			}
		}
	}
}

int main() {
	cin >> com;
	cin >> e;

	for (int i = 0; i < e; i++) {
		int a, b;
		cin >> a >> b;

		// ���� ����Ʈ
		list[a].push_back(b);
		list[b].push_back(a);
	}

	//DFS(1);
	BFS(1);

	cout << idx;
	cout << idx2;

	return 0;
}

