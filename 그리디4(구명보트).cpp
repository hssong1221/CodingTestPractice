#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <deque>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;

    deque<int> p;
    for (auto pe : people)
        p.push_back(pe);

    sort(p.begin(), p.end());
    
    // 맨 앞사람이 limit넘으면 모두가 혼자 타야함
    if (p.front() > limit / 2) {
        answer = people.size();
        return answer;
    }
    while(true) {
        // 사람이 1명 남으면 태우고 끝
        if (p.size() == 1) {
            answer++;
            break;
        }
        else if (p.size() == 0)
            break;

        //최대 인원 2명이니까 제일 무거운놈 가벼운놈 태움
        if (p[0] + p.back() <= limit) {
            p.pop_back();
            p.pop_front();
            answer++;
        }
        // 무거워서 못타면 무거운사람 혼자탐
        else {
            p.pop_back();
            answer++;
        }
    }
    cout << answer;

    return answer;
}

int main() {
    solution({ 70,50,  80,50 }, 100);
    return 0;
}