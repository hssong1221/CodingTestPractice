#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>
#include <set>
#include <iostream>

using namespace std;

// 교집합 구하기
int solution(vector<string> s1, vector<string> s2) {
    int answer = 0;
    vector<string> buff(s1.size() + s2.size());
    set<string> ss1;
    set<string> ss2;
    set<string> temp;

    for (auto s : s1)
        ss1.insert(s);
    for (auto s : s2)
        ss2.insert(s);

    set_intersection(ss1.begin(), ss1.end(), ss2.begin(), ss2.end(), inserter(temp, temp.begin()));

    answer = temp.size();
    return answer;
}

int main(void) {
    solution({ "a", "b", "c" }, { "com", "b", "d", "p", "c" });
    return 0;
}