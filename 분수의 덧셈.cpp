#include <iostream>
#include <vector>
#include <iostream>

using namespace std;

int GCD(int a, int b) {
	int temp = 0;

	while (b != 0) {
		temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}
int LCM(int a, int b, int c) {
	int result = a * b / c;
	return result;
}

vector<int> solution(int denum1, int num1, int denum2, int num2) {
	vector<int> answer;
	// 일단 기약분수로 만든다.
	int g1 = GCD(denum1, num1);
	int d1 = denum1 / g1;
	int n1 = num1 / g1;
	int g2 = GCD(denum2, num2);
	int d2 = denum2 / g2;
	int n2 = num2 / g2;

	// 계산한다
	int gcd = GCD(n1, n2);
	int lcm = LCM(n1, n2, gcd);
	int child = (d1 * (lcm / n1)) + (d2 * (lcm / n2));

	// 계산 한거를 또 기약분수로 만든다.
	int r = GCD(child, lcm);
	answer.push_back(child / r);
	answer.push_back(lcm / r);
	return answer;
}

int main() {
	solution(1,2,3,2);
	return 0;
}