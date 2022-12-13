#include <string>
#include <vector>
#include <map>
#include <algorithm>

#include <iostream>

using namespace std;

vector<int> solution(vector<int> emergency) {
    vector<int> answer;
    vector<int> temp;
    map<int, int> m;
    temp = emergency;
    int i = 1;

    sort(emergency.begin(), emergency.end(), greater<>());

    for (auto e : emergency) {
        m[e] = i++;
    }

    for (int i = 0; i < emergency.size(); i++) {
        answer.push_back(m[temp[i]]);
    }
    return answer;
}

int main(void) {
    solution({ 3,76,24 });
    return 0;
}
