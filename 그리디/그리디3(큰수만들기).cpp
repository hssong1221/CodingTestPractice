#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

string solution(string number, int k) {
    string answer = "";

    vector<string> num;
    string a = "";
    for (auto n : number) {
        a.push_back(n);
        num.push_back(a);
        a.clear();
    }
    int len = number.length();
    vector<string> temp;
    temp.push_back(num[0]);
    for (int i = 1; i < len; i++) {
        // ��� �� �ֱ�
        if (temp.empty()) {
            temp.push_back(num[i]);
            continue;
        }
        // �� ������ �ڿ� �׳� ������
        if (k == 0)
            temp.push_back(num[i]);
        //�ڿ� ���°� �� ũ�� �̹� ������ ���� �� ���
        else if (temp.back() < num[i]) {
            temp.pop_back();
            k--;
            i--;
        }
        // ���� �̹� ũ�� �� �ֱ�
        else if (temp.back() >= num[i]) 
            temp.push_back(num[i]);
        
    }
    // �� �� �������� �ڿ��� ���� ����
    while (k != 0) {
        temp.pop_back();
        k--;
    }

    for (auto t : temp)
        answer += t;

    cout << answer;

    return answer;
}

int main() {

    solution("654321", 1);
    return 0;
}