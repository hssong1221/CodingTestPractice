#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <algorithm>
#include <iostream>

using namespace std;

unordered_map<string, vector<int>> map;

// ����� ������ ������� �ʿ� �߰� (16����)
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

    // info �ٿ��� ����
    for (int i = 0; i < info.size(); i++) {
        istringstream iss(info[i]);
        // ���� �������� ���ʴ�� ��
        iss >> s[0] >> s[1] >> s[2] >> s[3] >> temp;
        addCase(s, stoi(temp));
    }

    // �� value�� �ִ°� ���� 
    for (auto it = map.begin(); it != map.end(); it++) {
        sort(it->second.begin(), it->second.end());
    }

    for (int i = 0; i < query.size(); i++) {
        istringstream iss(query[i]);
        // and �� �� temp������ ��������.
        iss >> s[0] >> temp >> s[1] >> temp >> s[2] >> temp >> s[3] >> temp;
        int score = stoi(temp);
        
        //�� value ���ĵȰ� ������
        vector <int> v = map[s[0] + s[1] + s[2] + s[3]];

        // ����Ž���ϱ�
        if (v.size() != 0) {
            // �������� ū���ڰ� ������ �ε��� ��ȯ
            int idx = lower_bound(v.begin(), v.end(), score) - v.begin();
            // ��ü �������� �ε������� ���� ���� ū ���� ����
            answer.push_back(v.size() - idx);
        }
        // query�� info�� �ϳ��� ������ 0
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