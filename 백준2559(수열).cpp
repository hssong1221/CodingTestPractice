// ������ ��������
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	vector<int> psum(100001, 0); // ���� ��
	vector<int> tsum; // �µ� ��
	// �Է�
	int N, K;
	cin >> N >> K;

	//������
	int n = 0;
	int temp = 0;
	for (int i = 1; i <= N; i++) {
		cin >> n;
		temp += n;
		psum[i] = temp;
	}

	// ���������� �κ��� ���
	int sum = 0;
	for (int i = 0; i <= N - K; i++) {
		sum = psum[i + K] - psum[i];
		tsum.push_back(sum);
	}


	// �������� �� �� ����ŭ
	sort(tsum.begin(), tsum.end(), greater<>());

	int answer = tsum[0];
	cout << answer;

	return 0;
}