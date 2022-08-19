#include<string>
#include <iostream>
#include <vector>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    vector<string> temp;

    for (int i = 0; i < s.length(); i++) {
        // ��ȣ ����
        if (s[i] == '(') {
            temp.push_back("(");
        }
        // ��ȣ ����
        else {
            // �����鼭 �������� �ϳ� ����
            // ���� �ȵŸ� false
            if (temp.empty()) {
                answer = false;
                break;
            }
            temp.pop_back();
        }
    }

    // �����϶� ¦���缭 ���� ���������
    if (!temp.empty())
        answer = false;
    
    cout << answer;

    return answer;
}

int main() {
    solution("(()(");
    return 0;
}