#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <unordered_map>
#include <iostream>
#include <set>
using namespace std;

vector<string> split(string input, char delimiter) {
    vector<string> result;
    stringstream ss(input);
    string temp;

    while (getline(ss, temp, delimiter)) result.push_back(temp);

    return result;
}

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(), 0);
    string last = "";
    string now = "";
    unordered_map<string, set<string>> m;
    unordered_map<string, int> ans;
    
    for (int i = 0; i < id_list.size(); i++) {
        ans[id_list[i]] = i;
    }

    for (int i = 0; i < report.size(); i++) {
        now = report[i];
        if (last == now)
            continue;
        
        vector<string> result = split(report[i], ' ');
        m[result[1]].insert(result[0]);
    }

    for (auto it : m) {
        if (it.second.size() >= k) {
            for (auto s_it : it.second) {
                int temp = ans[s_it];
                answer[temp]++;
            }
        }
    }

    for (auto a : answer)
        cout << a << " ";

    return answer;
}

int main() {
    solution({ "muzi", "frodo", "apeach", "neo" }, { "muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi" }, 2);
    //solution({ "con", "ryan" }, { "ryan con","ryan con","ryan con","ryan con","ryan con" }, 3);
    return 0;
}