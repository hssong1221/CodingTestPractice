#include <string>
#include <vector>

using namespace std;


int solution(string word) {
    int answer = 0;
    int len = word.length();

    // AEIOU 
    // 대충 이런식
    // ...
    // AAAAA 5
    // AAAAE 6
    // ... 
    // AAAAU 9
    // AAAE  10
    // AAAEA 11
    // ...
    // AAAI  16

    vector<int> count = { 781,156,31,6,1 };

    for (int i = len - 1; 0 <= i; i--) {
        if (word[i] == 'A') {

        }
        else if (word[i] == 'E') {

        }
        else if (word[i] == 'I') {

        }
        else if (word[i] == 'O') {

        }
        else if (word[i] == 'U') {

        }
    }

    return answer;
}

int main() {
    solution("AAAAE");
    return 0;
}