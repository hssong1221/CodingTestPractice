#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> factor(int a) { // 노랑이의 약수를 구해
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
		if (brown == (temp[i] * 2) + (yellow/temp[i] * 2) + 4 ) { // 갈색 = (노랑 가로 * 2) + (노랑 세로 * 2) + 4(모서리)
			answer.push_back(yellow/temp[i] + 2); //가로가 더 길고 갈색은 노랑이 보다 항상 가로 세로 + 2
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