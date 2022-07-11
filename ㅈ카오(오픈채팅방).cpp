#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <iostream>

using namespace std;

vector<string> split(string input, char delimiter) {
    vector<string> result;
    stringstream ss(input);
    string temp;

    while (getline(ss, temp, delimiter)) 
        result.push_back(temp);

    return result;
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<string> uid;
    vector<string> result;
    map<string, string> m;
    
    for (int i = 0; i < record.size(); i++) {
        result = split(record[i], ' ');

        if (result[0] == "Enter") {
            m[result[1]] = result[2];
            answer.push_back("´ÔÀÌ µé¾î¿Ô½À´Ï´Ù.");
            uid.push_back(result[1]);
        }
        else if (result[0] == "Leave") {
            answer.push_back("´ÔÀÌ ³ª°¬½À´Ï´Ù.");
            uid.push_back(result[1]);
        }
        else if (result[0] == "Change") {
            m[result[1]] = result[2];
        }
    }
    vector<string> temp;
    for (int i = 0; i < answer.size(); i++) {
        temp.push_back(m[uid[i]] + answer[i]);
    }
    return temp;
}

int main() {
    solution({ "Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan" });
    return 0;
}