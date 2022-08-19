#include <string>
#include <vector>
#include <deque>
#include <sstream>
#include <algorithm>
#include <iostream>
using namespace std;

// 입력값 분해할 때 사용
vector<string> split(string input, char delimeter) {
    vector<string> result;
    stringstream ss(input);
    string temp;

    while (getline(ss, temp, delimeter))
        result.push_back(temp);

    return result;
}

vector<int> solution(vector<string> operations) {
    vector<int> answer = { 0,0 };   // 기본값
    deque<int> d;   // 앞뒤로 제거하기 때문에 덱을 사용해 보았다. 
    vector<string> result;

    for (int i = 0; i < operations.size(); i++) {
        // 입력값 분석
        result = split(operations[i], ' ');
        if (result[0] == "I") {
            d.push_back(stoi(result[1]));
            // 덱은 자동정렬이 안되기때문에 직접해준다. 
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
        answer[0] = d.back();// 최댓값
        answer[1] = d.front();  //최솟값
    }

    cout << answer[0] << " " << answer[1];
    return answer;
}

int main() {
    solution({ "I 7","I 5","I -5","D -1" });
    return 0;
}