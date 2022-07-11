#include <iostream>
#include <vector>

using namespace std;

// ���ڿ�
string s;
// �湮 ����
vector<int> visit(51, 0);

int DFS(int index) {

	// ( ) �� ���� ���� 
	int num = 0;

	//���ڿ� �ϳ��� �˻�(����϶� �� idx����)
	for (int i = index; i < s.size(); i++) {
		
		// ó������ ���� ��ȣ
		if (s[i] == '(' && visit[i] == 0) {
			visit[i] = 1;
			int multiple = s[i - 1] - '0'; // char -> int
			num--; // ���� �� �� ���Ե� mutiple�� �������� ���ֱ�

			// '(' �� ���ڶ� �ڿ� ��ȣ ���� ���� ���� ���ؼ� ����
			// (() ())������ �ߺ��� ��� �տ��� ����ѰŸ�ŭ ���ϱ�
			num += multiple * DFS(i + 1) ;  
		}
		// ó������ �ݴ� ��ȣ
		else if (s[i] == ')' && visit[i] == 0) {
			visit[i] = 1;
			return num;
		}
		// ����
		else if(visit[i] == 0){
			visit[i] = 1;
			num++;
		}
	}
	//���������� �� ���Ѱ� 
	return num;
}

int main() {
	//�Է�
	cin >> s;

	int answer = 0;
	answer = DFS(0);

	//���
	cout << answer;
	return 0;
}


