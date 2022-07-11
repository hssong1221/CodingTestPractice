#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <algorithm>
#include <iostream>

using namespace std;

unordered_map<string, vector<int>> map;

// 만들기 가능한 종류대로 맵에 추가 (16가지)
void addCase(string *s, int num) {
    for (int i = 0; i < 16; i++) {
        string temp = "";
        int n = i;
        for (int j = 3; j >= 0; j--) {
            if (n <= 0 || n % 2 == 0) {
                temp = "-" + temp;
            }
            else
                temp = s[j] + temp;

            n /= 2;
        }
        //cout << temp << endl;
        map[temp].push_back(num);
    }
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;

    string s[4];
    string temp = "";

    // info 붙여서 보냄
    for (int i = 0; i < info.size(); i++) {
        istringstream iss(info[i]);
        // 띄어쓰기 기준으로 차례대로 들어감
        iss >> s[0] >> s[1] >> s[2] >> s[3] >> temp;
        addCase(s, stoi(temp));
    }

    // 맵 value에 있는거 정렬 
    for (auto it = map.begin(); it != map.end(); it++) {
        sort(it->second.begin(), it->second.end());
    }

    for (int i = 0; i < query.size(); i++) {
        istringstream iss(query[i]);
        // and 는 다 temp때문에 없어진다.
        iss >> s[0] >> temp >> s[1] >> temp >> s[2] >> temp >> s[3] >> temp;
        int score = stoi(temp);
        
        //맵 value 정렬된거 가져옴
        vector <int> v = map[s[0] + s[1] + s[2] + s[3]];

        // 이진탐색하기
        if (v.size() != 0) {
            // 점수보다 큰숫자가 나오는 인덱스 반환
            int idx = lower_bound(v.begin(), v.end(), score) - v.begin();
            // 전체 갯수에서 인덱스빼면 점수 보다 큰 개수 나옴
            answer.push_back(v.size() - idx);
        }
        // query가 info에 하나도 없으면 0
        else {
            answer.push_back(0);
        }
    }
    return answer;
}


int main() {
    solution({ "java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50" },
        { "java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150" });
    return 0;
}