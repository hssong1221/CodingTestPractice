#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> factor(int a) { // ������� ����� ����
	vector<int> result;

	for (int i = 1; i * i <= a; i++) {

		if (i * i == a) {
			result.push_back(i);
		}
		else if (a % i == 0) {
			result.push_back(i);
		}
	}

	sort(result.begin(), result.end());

	return result;
}

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
	vector<int> temp;

	temp = factor(yellow);

	for (int i = 0; i < temp.size(); i++) {
		if (brown == (temp[i] * 2) + (yellow/temp[i] * 2) + 4 ) { // ���� = (��� ���� * 2) + (��� ���� * 2) + 4(�𼭸�)
			answer.push_back(yellow/temp[i] + 2); //���ΰ� �� ��� ������ ����� ���� �׻� ���� ���� + 2
			answer.push_back(temp[i] + 2);
		}
	}

	cout << answer[0];
	cout << answer[1];

    return answer;
}



int main() {
	solution(24, 24);
	return 0;
}