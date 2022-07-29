#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

/// <summary>
/// A(1) -> AAAAA(5) 
/// AAAAA -> 1 1 1 1 1  자릿수마다 1씩 기본적으로 더해짐
/// AAAAA -> AAAAE      1증가
/// AAAE        1 + 1 + 1 + (1 + 1 * 6)) 
/// I           1 + (781 * 2)
/// EIO         1 + (1 + 781 * 1) + (1 + 156 * 2) + (1 + 31 * 3)
/// </summary>

int solution(string word) {
    int answer = 0;
    int len = word.length();

    map<string, int> m;
    m["A"] = 0;
    m["E"] = 1;
    m["I"] = 2;
    m["O"] = 3;
    m["U"] = 4;
    vector<int> count = { 781,156,31,6,1 };

    for (int i = 0; i < word.length(); i++) {
        string temp = "";
        temp += word[i];
        answer += 1 + m[temp] * count[i];
    }
    cout << answer;
    return answer;
}

int main() {
    solution("EIO");
    return 0;
}