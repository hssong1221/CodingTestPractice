#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
	//�Է�
	
	int N;
	cin >> N;

	// �����
	vector<int> ans(1000000, -1);
	// �����
	vector<int> list(1000000, 0);
	// ��ġ �����(�ڿ������� Ȯ��)
	stack<int> s;


	// �Է�
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}

	for (int i = 0; i < N; i++) {
		// ������ ������� �ʰ� ������ ���ں��� �� ū������ ��
		while (!s.empty() && list[s.top()] < list[i]) {
			// ������ ���ڸ� �� ū���ڷ� �ٲٰ� 
			// ���ÿ��� ��ġ�� ������ ��ū���� Ȯ���� ���� ����
			ans[s.top()] = list[i];
			s.pop();
		}
		s.push(i);
	}

	for (int i = 0; i < N; i++)
		cout << ans[i] << " ";

	return 0;
}
