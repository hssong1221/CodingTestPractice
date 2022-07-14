#include <iostream>
#include <vector>

using namespace std;

int main() {
	int answer = 0;
	//�Է�
	int H, W;
	cin >> H >> W;
	vector<int> v(W, 0);
	for (int i = 0; i < W; i++) {
		int a;
		cin >> a;
		v[i] = a;
	}

	//���ʺ���
	int max = 0;
	int temp = 0;
	for (int i = 0; i < W; i++) {
		if (max <= v[i]) {
			max = v[i];
			answer += temp;
			temp = 0;
		}
		else {
			temp += max - v[i];
		}
	}
	//������ 
	max = 0;
	temp = 0;
	for (int i = W - 1; 0 < i; i--) {
		if (max < v[i]) {
			max = v[i];
			answer += temp;
			temp = 0;
		}
		else {
			temp += max - v[i];
		}
	}
	cout << answer;

	return 0;
}