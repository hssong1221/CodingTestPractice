#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int main() {
	// ���� ������� ����
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	//�Է�
	int N = 0;
	int M = 0;
	cin >> N >> M;

	// prefix sum
	// ������ = ps[k] - ps[i]
	// (ps[k] - ps[i]) % MOD = 0���ϱ�
	// ps[k] % MOD = ps[i] % MOD ����(���� ������)
	// 
	// ps[i] % MOD �ϰ� ���� ������ ���� ���ϱ�
	vector<long long> psMOD(1001, 0);
	long long temp = 0;
	long long A = 0;
	for (int i = 0; i < N; i++) {
		cin >> A;
		temp += A;
		psMOD[temp % M]++;
	}

	// ���� �������� �� �߿��� 2�� �̴� �� �̰� (���� �ں��� ū ��ȣ�� ���� (1,2) - (2, 1)x )
	// +
	// ps[i] % MOD = 0 �ΰ� ����
	long long answer = 0;
	for (int i = 0; i <= 1000; i++) {
		answer += (psMOD[i] * (psMOD[i] - 1)) / 2;
	}
	// ���
	cout << answer + psMOD[0];

	return 0;
}