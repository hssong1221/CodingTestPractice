#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
	//�Է�
	stack<int> s;
	int N;
	cin >> N;

	// �ڽ� ������ ���° ���� ��ū���� ������
	vector<pair<int, bool>> list(1000000, { 0, false });
	// �����
	vector<int> ans(1000001, -1);
	// �ִ밪 �Ǻ�
	int max = 0;
	//
	int idx = 0;

	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;

		list[i].first = a;
		// ����top���� �� ���ڰ� Ŭ �� ��ū��
		if (i != 0) {
			if (s.top() < a) {
				// ��⿭
				for (int k = idx; k < i + 1; k++) {
					if (list[k].first < a) {
						ans[k] = a;
					}
				}
				idx = i;
			}
			// �۴ٸ� ��⿭�� ��
			else {
				idx = i;
			}
		}

		s.push(a);
	}

	// �������� -1
	ans[N] = -1;

	for (int i = 0; i <= N; i++)
		cout << ans[i] << " ";

	return 0;
}
