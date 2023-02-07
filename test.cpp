#include <string>
#include <vector>
#include <iostream>
#include <climits>
#include <map>
#include <sstream>
#include <set>
#include <algorithm>
#include <bitset>
#include <deque>
#include <unordered_map>
#include <queue>

using namespace std;

vector<vector<int>> v(32, vector<int>(32, 0));

void DFS(int x, int y, int n, string::iterator& iter) {
	char c = *iter;
	cout << c << endl;
	iter++;

	if (c == 'b' || c == 'w') {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				v[i + x][j + y] = (c == 'b' ? 1 : 0);
			}
		}
	}
	else {
		int half = n / 2;
		DFS(x, y, half, iter);
		DFS(x + half, y, half, iter);
		DFS(x + half, y + half, half, iter);
		DFS(x, y + half, half, iter);
	}
}

int solution(string S1, string S2) {
	int answer = 0;
	int n = 32;

	string::iterator iter = S1.begin();

	DFS(0, 0, n, iter);


	for (auto a : v) {
		for (auto b : a) {
			cout << b << " ";
		}
		cout << endl;
	}


	return answer;
}

int main() {
	solution("ppwwwbpbbwwbw", "ppwwwbpbbwwbw");
	return 0;
}
