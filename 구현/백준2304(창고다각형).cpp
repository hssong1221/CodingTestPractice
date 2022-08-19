#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

vector<int> v(1001);
int main() {
	int answer = 0;
	// �Է�
	cin >> n;
	for (int i = 0; i < n; i++) {
		int L, H;
		cin >> L >> H;
		v[L] = H;
	}

	//���ʺ��� Ȯ��
	int max = 0;
	int temp = 0;
	for (int i = 0; i < v.size(); i++) {
		if (max <= v[i]) {
			// ���ݱ��� ������ ���ϱ�
			answer += temp;
			temp = 0;
			//�ִ�
			max = v[i];
			// ���� ����
			temp += max;
		}
		else 
			temp += max;
	}
	//������ Ȯ��
	max = 0;
	temp = 0;
	for (int i = v.size() - 1; 0 < i; i--) {
		if (max < v[i]) {
			// ���ݱ��� ������ ���ϱ�
			answer += temp;
			temp = 0;
			//�ִ�
			max = v[i];
			// ���� ����
			temp += max;
		}
		else
			temp += max;
	}

	//���������� ���� ���� ��� ���ϱ�
	answer += max;

	cout << answer;
	return 0;
}
