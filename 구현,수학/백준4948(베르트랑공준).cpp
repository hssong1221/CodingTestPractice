#include <iostream>

using namespace std;

bool Prime(int n) {
	if (n < 2)
		return false;

	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0)
			return false;
	}
	return true;
}

int main() {
	while(true){
		int n;
		cin >> n;
		if (n == 0)
			break;

		int answer = 0;
		for (int i = n + 1; i <= 2 * n; i++) {
			if (Prime(i))
				answer++;
		}
		cout << answer << '\n';
	}
	return 0;
}