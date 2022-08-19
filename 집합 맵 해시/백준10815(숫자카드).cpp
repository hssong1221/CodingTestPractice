#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int main() {
	// �Է�
	int N, M;
	cin >> N;
	map<int, int> m;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		m[temp] = 1;
	}
	// �˻� ����Ʈ
	cin >> M;
	vector<int> v;
	vector<int> answer;
	for (int i = 0; i < M; i++) {
		int temp;
		cin >> temp;
		v.push_back(temp);
		answer.push_back(0);
	}
	// �ʿ� �ִ��� ������ Ȯ��
	for (int i = 0; i < v.size(); i++) {
		if (m[v[i]] == 1) {
			answer[i] = 1;
		}
	}

	//���
	for (auto a : answer)
		cout << a << " ";
	return 0;
}