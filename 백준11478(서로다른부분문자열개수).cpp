#include <string>
#include <set>
#include <iostream>

using namespace std;

int main() {
	// �Է�
	string s = "";
	cin >> s;

	set<string> set;
	int idx = 0;
	for (int i = 1; i < s.length(); i++) {
		for (int k = 0; k < s.length(); k++) {
			if (s.length() - i < k)
				break;
			set.insert(s.substr(k, i));
		}
	}
	// �ڱ��ڽ� ����
	cout << set.size() + 1;
	return 0;
}