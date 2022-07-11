#include <string>
#include <vector>
#include <deque>
#include <sstream>
#include <algorithm>
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

vector<int> solution(vector<string> operations) {
    vector<int> answer = {0,0};
    deque<int> d;
    vector<string> result;

    for (int i = 0; i < operations.size(); i++) {
        result = split(operations[i], ' ');
        if (result[0] == "I") {
            d.push_back(stoi(result[1]));
            sort(d.begin(), d.end());
        }
        else if (result[0] == "D") {
            if (d.empty()) {
                continue;
            }
            if (result[1] == "-1")
                d.pop_front();
            else if (result[1] == "1")
                d.pop_back();
        }
    }
    if (!d.empty()) {
        answer[0] = d.back();
        answer[1] = d.front();
    }

    cout << answer[0] << " " << answer[1];

    return answer;
}

int main() {
    solution({ "I 7","I 5","I -5","D -1" });
    return 0;
}