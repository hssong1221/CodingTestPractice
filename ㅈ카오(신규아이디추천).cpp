#include <string>
#include <vector>
#include <iostream>
#include <regex>

using namespace std;

string solution(string new_id) {
    string answer = "";
    string id = new_id;
    for (int i = 0; i < id.length(); i++) {
        if ('A' <= id[i] && id[i] <= 'Z')
            id[i] = tolower(id[i]);
    }

    id = regex_replace(id, regex("[~!@#\$%\^&\*\(\)=\+\[\{\\]\}:\?,<>/]"), "");

    for (int i = 0; i < id.length(); i++) {
        if (id[i] == '.' && id[i + 1] == '.') {
            id.erase(id.begin() + i);
            i--;
        }
    }

    if (id.front() == '.')
        id.erase(id.begin());    
    
    if (id.back() == '.')
        id.pop_back();

    if (id.empty())
        id.push_back('a');

    if (id.length() >= 16) {
        id = id.substr(0, 15);
        if (id.back() == '.')
            id.pop_back();
    }

    if (id.length() <= 2) {
        while (id.length() != 3)
            id.push_back(id.back());
    }

    answer = id;
    return answer;
}

int main() {
    solution("z-+.^.");
    return 0;
}