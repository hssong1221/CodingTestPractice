#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
	//�Է�
	stack<int> s;
	int N;
	cin >> N;

	// �����
	vector<int> ans(1000000, -1);
	// �ڽ� ������ ���° ���� ��ū���� ������
	vector<int> list(1000000, 0);
	int cnt = 0;

	for (int i = 0; i < N; i++) {
		int a = 0;
		cin >> a;
		
		// ù��° ���� �Է�
		if (i == 0) {
			list[i] = a;
		}
		else if (i != 0) {
			// ���� top ���� ���� �ִ� ���� ũ�� ��ū���� 
			if (s.top() < a) {
				// �и� ���� ��ŭ �ѹ��� �߰�
				for (int k = 0; k < cnt + 1; k++) {
					// �зȴ� ���ڵ麸�� Ŀ�� ��ū��
					if(list[i - cnt + k - 1] < a)
						ans[i - cnt + k ] = a;
				}
				cnt = 0;
			}
			// �۴ٸ� �и� ������ ���� ���� ����
			else {
				list[i] = a;
				cnt++;
			}
		}
		s.push(a);
	}
	// �������� -1
	ans[N] = -1;

	for (int i = 1; i <= N; i++)
		cout << ans[i] << " ";
	return 0;
}
