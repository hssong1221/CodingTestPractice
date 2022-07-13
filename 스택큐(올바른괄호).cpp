#include<string>
#include <iostream>
#include <vector>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    vector<string> temp;

    for (int i = 0; i < s.length(); i++) {
        // °ýÈ£ ¿­¸²
        if (s[i] == '(') {
            temp.push_back("(");
        }
        // °ýÈ£ ´ÝÈû
        else {
            // ´ÝÀ¸¸é¼­ ¿­¾ú´ø°Å ÇÏ³ª »èÁ¦
            // »èÁ¦ ¾ÈµÅ¸é false
            if (temp.empty()) {
                answer = false;
                break;
            }
            temp.pop_back();
        }
    }

    // Á¤»óÀÏ¶© Â¦¸ÂÃç¼­ ÀüºÎ »ç¶óÁ®¾ßÇÔ
    if (!temp.empty())
        answer = false;
    
    cout << answer;

    return answer;
}

int main() {
    solution("(()(");
    return 0;
}