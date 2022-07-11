#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;


string solution(vector<string> participant, vector<string> completion) {
	string answer = "";
	map<string, int> m;

	for (int i = 0; i < participant.size(); i++) {
		if (m[participant[i]] == 0)
			m[participant[i]] = 1;
		else 
			m[participant[i]]++;
	}

	for (int i = 0; i < completion.size(); i++) {
		m[completion[i]]--;
	}

	for (int i = 0; i < participant.size(); i++) {
		if (m[participant[i]] > 0)
			answer = participant[i];
	}

	return answer;
}

int main() {
	solution({ "marina", "josipa", "nikola", "vinko", "filipa" }, { "josipa", "filipa", "marina", "nikola" });
	return 0;
}