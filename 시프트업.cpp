#include<vector>
#include <map>

using namespace std;

//1
vector<int> solution(vector<int> arr) {
	vector<int> answer;
	map<int, int> m;

	// �ʿ� �ְ� value�� 1�ΰ͸� ������ �ȴ�. ������ �ڵ��̴�
	for (auto a : arr)
		m[a]++;

	for (auto iter = m.begin(); iter != m.end(); iter++) {
		if (iter->second == 1)
			answer.push_back(iter->first);
	}

	// ����ִٸ� -1
	if (answer.empty())
		answer.push_back(-1);

	return answer;
}
int main() {
	solution({ "3,4,4,2,5,2,5,5" });// �Ȱ�ġ�°͸� ������������
	return 0;
}

//2
vector<string> solution(vector<string> card, vector<string> word) {
	vector<string> answer = {};

	// word ������ŭ �ݺ�
	for (int i = 0; i < word.size(); i++) {
		bool flag = false;
		// 3���� �Ʒ��� �ѱ��
		if (word[i].length() < 3)
			continue;

		// �ʿ� ����ī�� ���� �ֱ�
		map<char, int> m;
		for (auto ca : card) {
			for (auto c : ca)
				m[c]++;
		}

		// �켱 �ܾ ����� �ִ� ���� ���� �Ǵ�
		for (int j = 0; j < word[i].length(); j++) {
			char ch = word[i][j];
			if (m[ch] == 0)
				flag = true;
			else
				m[ch]--;
		}
		if (flag)
			continue;

		// 1,2,3 ��° �ٿ� �� ����־����
		vector<bool> check = { false, false,false };
		// ��� ����ִ°� Ȯ��
		for (int j = 0; j < word[i].length(); j++) {
			char ch = word[i][j];
			for (int k = 0; k < card.size(); k++) {
				if (card[k].find(ch) != string::npos)
					check[k] = true;
			}
		}

		// 3�� �� true�� answer�� �ֱ�
		if (check[0] && check[1] && check[2]) {
			answer.push_back(word[i]);
		}
	}

	// ���� ����  : -1
	if (answer.empty())
		answer.push_back("-1");

	return answer;
}
int main() {
	solution({ "ABACDEFG","NOPQRSTU","HIJKLKMM" }, { "GPQM","GPMZ","EFU","MMNA" }); // ���ٿ� �ѱ��ھ� �� �Ἥ ī�带 �ܾ� ����� �ֳ�
	return 0;
}
//3
long long solution(string block, int pos) {
	long long answer = 0;
	// ���� ���ε� ������ �ȴ�.
	// pos�� 1���� �����̴ϱ� robot[0]�̳� robot[block.size() + 1] ��ŭ �� �� ���� ���̶�� ġ��
	vector<int> robot(block.size() + 2, 0);
	robot[pos] = 1;

	// ���ʿ� ��� ������ ��� �ݺ�
	int time = 0;
	while (robot[0] == 0 && robot[block.size() + 1] == 0) {
		time++;
		// ������
		if (block[pos - 1] == '>') {
			robot[pos] = 0;
			robot[pos + 1] = 1;
			block[pos - 1] = '<';
			pos++;
		}
		// ����
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
//3 �ð��ʰ� �ذ�
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