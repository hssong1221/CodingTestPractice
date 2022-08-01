#include <iostream>
#include <vector>

using namespace std;

// 문자열
string s;
// 방문 여부
vector<int> visit(51, 0);

int DFS(int index) {

	// ( ) 안 숫자 갯수 
	int num = 0;

	//문자열 하나씩 검사(재귀일땐 그 idx부터)
	for (int i = index; i < s.size(); i++) {
		
		// 처음보는 여는 괄호
		if (s[i] == '(' && visit[i] == 0) {
			visit[i] = 1;
			int multiple = s[i - 1] - '0'; // char -> int
			num--; // 숫자 셀 때 포함된 mutiple은 갯수에서 빼주기

			// '(' 앞 숫자랑 뒤에 괄호 사이 숫자 갯수 곱해서 저장
			// (() ())식으로 중복된 경우 앞에서 계산한거만큼 더하기
			num += multiple * DFS(i + 1) ;  
		}
		// 처음보는 닫는 괄호
		else if (s[i] == ')' && visit[i] == 0) {
			visit[i] = 1;
			return num;
		}
		// 숫자
		else if(visit[i] == 0){
			visit[i] = 1;
			num++;
		}
	}
	//마지막까지 다 더한것 
	return num;
}

int main() {
	//입력
	cin >> s;

	int answer = 0;
	answer = DFS(0);

	//출력
	cout << answer;
	return 0;
}


