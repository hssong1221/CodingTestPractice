#include<vector>
#include <map>

using namespace std;

//1
vector<int> solution(vector<int> arr) {
	vector<int> answer;
	map<int, int> m;

	// 맵에 넣고 value가 1인것만 뽑으면 된다. 정렬은 자동이니
	for (auto a : arr)
		m[a]++;

	for (auto iter = m.begin(); iter != m.end(); iter++) {
		if (iter->second == 1)
			answer.push_back(iter->first);
	}

	// 비어있다면 -1
	if (answer.empty())
		answer.push_back(-1);

	return answer;
}
int main() {
	solution({ "3,4,4,2,5,2,5,5" });// 안겹치는것만 오름차순정렬
	return 0;
}

//2
vector<string> solution(vector<string> card, vector<string> word) {
	vector<string> answer = {};

	// word 개수만큼 반복
	for (int i = 0; i < word.size(); i++) {
		bool flag = false;
		// 3글자 아래면 넘기기
		if (word[i].length() < 3)
			continue;

		// 맵에 글자카드 갯수 넣기
		map<char, int> m;
		for (auto ca : card) {
			for (auto c : ca)
				m[c]++;
		}

		// 우선 단어가 만들수 있는 건지 부터 판단
		for (int j = 0; j < word[i].length(); j++) {
			char ch = word[i][j];
			if (m[ch] == 0)
				flag = true;
			else
				m[ch]--;
		}
		if (flag)
			continue;

		// 1,2,3 번째 줄에 다 들어있어야함
		vector<bool> check = { false, false,false };
		// 어디에 들어있는가 확인
		for (int j = 0; j < word[i].length(); j++) {
			char ch = word[i][j];
			for (int k = 0; k < card.size(); k++) {
				if (card[k].find(ch) != string::npos)
					check[k] = true;
			}
		}

		// 3줄 다 true면 answer에 넣기
		if (check[0] && check[1] && check[2]) {
			answer.push_back(word[i]);
		}
	}

	// 답이 없다  : -1
	if (answer.empty())
		answer.push_back("-1");

	return answer;
}
int main() {
	solution({ "ABACDEFG","NOPQRSTU","HIJKLKMM" }, { "GPQM","GPMZ","EFU","MMNA" }); // 한줄에 한글자씩 꼭 써서 카드를 단어 만들수 있나
	return 0;
}
//3
long long solution(string block, int pos) {
	long long answer = 0;
	// 양쪽 어디로든 나가면 된다.
	// pos가 1부터 시작이니까 robot[0]이나 robot[block.size() + 1] 만큼 갈 때 양쪽 끝이라고 치면
	vector<int> robot(block.size() + 2, 0);
	robot[pos] = 1;

	// 양쪽에 닿기 전까지 계속 반복
	int time = 0;
	while (robot[0] == 0 && robot[block.size() + 1] == 0) {
		time++;
		// 오른쪽
		if (block[pos - 1] == '>') {
			robot[pos] = 0;
			robot[pos + 1] = 1;
			block[pos - 1] = '<';
			pos++;
		}
		// 왼쪽
		else {
			robot[pos] = 0;
			robot[pos - 1] = 1;
			block[pos - 1] = '>';
			pos--;
		}
	}
	answer = time;
	return answer;
}

int main() {
	solution({ ">><" }, 1);
	return 0;
}
//3 시간초과 해결
long long solution(string block, int pos) {
	long long answer = 0;
	queue<int> right;
	queue<int> left;


	if (block[pos - 1] == '>') {
		int p = pos;
		int a;
		while ((a = block.find_first_of('<', p)) != string::npos) {
			right.push(a);
			p = a + 1;
		}
		p = pos - 1;
		while ((a = block.find_last_of('>', p - 1)) != string::npos) {
			if (p <= 0)
				break;
			left.push(a);
			p = a;
		}

		bool flag = false;
		int temp = pos - 1;
		int loop = right.size() * 2;
		for (int i = 0; i < loop; i++) {
			cout << "answer : " << answer << endl;
			if (i % 2 == 0) {
				cout << "temp : " << temp << endl;
				answer += abs(temp - right.front());
				temp = right.front();
				right.pop();
			}
			else {
				cout << "temp : " << temp << endl;
				if (left.empty()) {
					flag = true;
					break;
				}
				answer += abs(temp - left.front());
				temp = left.front();
				left.pop();
			}

		}
		cout << "temp : " << temp << endl;
		if (flag)
			answer += temp + 1;
		else
			answer += abs(temp - (int)block.length());
		cout << "answer : " << answer << endl;

	}
	else if (block[pos - 1] == '<') {
		int p = pos;
		int a;
		while ((a = block.find_first_of('<', p)) != string::npos) {
			right.push(a);
			p = a + 1;
		}
		p = pos - 1;
		while ((a = block.find_last_of('>', p - 1)) != string::npos) {
			if (p <= 0)
				break;
			left.push(a);
			p = a;
		}


		bool flag = false;
		int temp = pos - 1;
		int loop = left.size() * 2;
		for (int i = 0; i < loop; i++) {
			cout << "answer : " << answer << endl;
			if (i % 2 == 0) {
				cout << "temp : " << temp << endl;
				answer += abs(temp - left.front());
				temp = left.front();
				left.pop();
			}
			else {
				cout << "temp : " << temp << endl;
				if (right.empty()) {
					flag = true;
					break;
				}
				answer += abs(temp - right.front());
				temp = right.front();
				right.pop();
			}

		}
		cout << "temp : " << temp << endl;
		if (!flag)
			answer += temp + 1;
		else
			answer += abs(temp - (int)block.length());
		cout << "answer : " << answer << endl;
	}

	cout << answer;

	return answer;
}

int main() {
	solution("<<><<", 2);
	return 0;
}
//4