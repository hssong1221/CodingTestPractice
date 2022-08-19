#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// 각 사람이 찍는 방식
vector<int> num1 = { 1,2,3,4,5 };
vector<int> num2 = { 2,1,2,3,2,4,2,5 };
vector<int> num3 = { 3,3,1,1,2,2,4,4,5,5 };

vector<int> solution(vector<int> answers) {
    vector<int> answer;

    int temp[3] = { 0,0,0 };
    int maxnum = 0;

    // 각 방식별로 자기 방식대로 차례대로 찍어서 비교
    for (int i = 0; i < answers.size(); i++) {
        if (answers[i] == num1[i % 5]) {
            temp[0]++;
        }
        if (answers[i] == num2[i % 8]) {
            temp[1]++;
        }
        if (answers[i] == num3[i % 10]) {
            temp[2]++;
        }
    }
    // 맞은 문제 최대 갯수
    maxnum = max(max(temp[0], temp[1]), temp[2]);

    // 제일 많이 맞춘사람 추가
    for (int k = 1; k <= 3; k++)
    {
        if (temp[k - 1] == maxnum) {
            answer.push_back(k);
        }
    }

    for (auto a : answer)
        cout << a << " ";

    return answer;
}

int main() {
    solution({ 1,2,3,4,5 });
    return 0;
}