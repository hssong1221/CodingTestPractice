#include <vector>
#include <string>
#include <iostream>
#include <map>

using namespace std;

int main() {
	int answer = 0;
	// �Է�
	int N, M;
	cin >> N >> M;
	map<string, int> m;
	for (int i = 0; i < N; i++) {
		string temp = "";
		cin >> temp;
		m[temp] = 1;
	}

	// �˻� ����Ʈ
	vector<string> v;
	for (int i = 0; i < M; i++) {
		string temp = "";
		cin >> temp;
		v.push_back(temp);
	}
	// �ʿ� �ִ��� ������ Ȯ��
	for (int i = 0; i < v.size(); i++) {
		// begin()���� end()���� Ȯ���ϴ� ������ end()���� ����
		auto k = m.find(v[i]);
		if (k != m.end())
			answer++;
	}
	
	//���
	cout << answer;
	return 0;
}