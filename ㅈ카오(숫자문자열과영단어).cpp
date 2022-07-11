#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = 0;
    vector<string> v;
    string temp = "";

    for (int i = 0; i < s.length(); i++) {
        temp = "";
        if ('0' <= s[i] && s[i] <= '9') {
            temp += s[i];
            v.push_back(temp);
            continue;
        }

        if (s[i] == 'z') {
            v.push_back("0");
            i += 3;
        }
        else if (s[i] == 'o') {
            v.push_back("1");
            i += 2;
        }
        else if (s[i] == 't') {
            if (s[i + 1] == 'w') {
                v.push_back("2");
                i += 2;
            }
            else {
                v.push_back("3");
                i += 4;
            }
        }
        else if (s[i] == 'f') {
            if (s[i + 1] == 'o') {
                v.push_back("4");
                i += 3;
            }
            else {
                v.push_back("5");
                i += 2;
            }
        }
        else if (s[i] == 's') {
            if (s[i + 1] == 'i') {
                v.push_back("6");
                i += 2;
            }
            else {
                v.push_back("7");
                i += 4;
            }
        }
        else if (s[i] == 'e') {
            v.push_back("8");
            i += 4;
        }
        else{
            v.push_back("9");
            i += 3;
        }
    }

    temp = "";
    for (auto a : v)
        temp += a;
    answer = stoi(temp);
    cout << answer;
    return answer;
}

int main() {
    solution("2100000000");
    return 0;
}