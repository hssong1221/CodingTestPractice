// ���� ��
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	// ���� ������� ����
	/*ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);*/
	// �Է�
	string S;
	cin >> S;
	
	// a - z ���� ������ ������(0���� S.length����)�� ����  ���ϱ�
	vector<vector<int>> psum(200001, vector<int>(26, 0));

	for (int i = 0; i < S.length(); i++) {
		int temp = S[i] - 97;
		psum[i][temp]++;
		if (i == 0)
			continue;

		for (int k = 0; k < 26; k++) { 
			psum[i][k] += psum[i - 1][k];
		}
	}

	char a;
	int l, r;
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		//�Է�
		cin >> a;
		cin >> l >> r;

		// r���� �����տ��� l-1 ������ ����
		int idx_a = a - 97;
		int result = 0;
		if(l == 0)
			result = psum[r][idx_a] ;
		else
			result = psum[r][idx_a] - psum[l - 1][idx_a];

		cout << result << "\n";
	}
	
	return 0;
}