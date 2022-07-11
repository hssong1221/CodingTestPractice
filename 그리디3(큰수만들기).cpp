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
        // 비면 걍 넣기
        if (temp.empty()) {
            temp.push_back(num[i]);
            continue;
        }
        // 다 뺐으면 뒤에 그냥 붙히기
        if (k == 0)
            temp.push_back(num[i]);
        //뒤에 오는게 더 크면 이미 넣은거 삭제 후 재비교
        else if (temp.back() < num[i]) {
            temp.pop_back();
            k--;
            i--;
        }
        // 앞이 이미 크면 걍 넣기
        else if (temp.back() >= num[i]) 
            temp.push_back(num[i]);
        
    }
    // 다 안 빠졌으면 뒤에서 부터 빼기
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