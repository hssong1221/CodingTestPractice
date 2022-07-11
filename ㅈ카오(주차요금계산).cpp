#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <iostream>
using namespace std;

vector<string> split(string input, char delimeter) {
    vector<string> result;
    stringstream ss(input);
    string temp;
    while (getline(ss, temp, delimeter))
        result.push_back(temp);

    return result;
}
vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    // ���̶� �ڵ� ����
    map<string, int> m;
    map<string, int> save;

    for (int i = 0; i < records.size(); i++) {
        // ���� ���� ����Ʈ �и�
        vector<string> list;
        list = split(records[i], ' ');

        vector<string> time;
        time = split(list[0], ':');
        int t = stoi(time[0]) * 60 + stoi(time[1]);

        // IN
        if (list[2].length() == 2) {
            m[list[1]] = t;
        }
        // OUT
        else {
            m[list[1]] = t - m[list[1]];
            save[list[1]] += m[list[1]];
            m[list[1]] = -1;
        }
    }
    // OUT �ȵȰ� 23:59�� ����
    for (auto a : m) {
        cout << a.first << " " << a.second << endl;

        if (a.second >= 0)
            save[a.first] += 1439 - a.second;
    }
    for (auto s : save) {
        cout << s.first << " " << s.second << endl;

        int temp = 0;

        // �⺻���
        if (s.second - fees[0] <= 0)
            answer.push_back(fees[1]);
        else {
            // �ø� = (a+b-1)/b
            temp = fees[1] + ((s.second - fees[0] + fees[2] - 1) / fees[2]) * fees[3];
            answer.push_back(temp);
        }
    }

    for (auto a : answer)
        cout << a << endl;
    
    return answer;
}

int main() {
    solution({ 1,461,1,10 }, { "00:00 1234 IN"  });
    return 0;
}