#include <string>
#include <vector>
#include <map>
#include <algorithm>
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
string solution(string letter) {
    string answer = "";
    vector<string> result;
    vector<string> az = { ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.." };
    map<string, char> morse;

    int i = 0;
    for (auto a : az) {
        morse[a] = 'a' + i;
        i++;
    }

    result = split(letter, ' ');
    for (auto r : result) {
        answer += morse[r];
    }

    cout << answer;

    return answer;
}

int main(void) {
    solution(".... . .-.. .-.. ---");
    return 0;
}