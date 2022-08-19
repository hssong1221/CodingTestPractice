#include <string>
#include <vector>
#include <iostream>
#include <deque>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    deque<int> dq;

    for (int i = 0; i < progresses.size(); i++) {
        // 남은 진행률 (100되면 바로 배포하기 때문에 작업 일수에 포함이 안됌 그래서 99에서 빼야함)
        int t = (99 - progresses[i]);

        // 작업 완료까지 남은 날짜
        dq.push_back((t / speeds[i]) + 1);
    }

    while (!dq.empty()) {
        int ans = 0;
        int criteria = dq.front(); // 기준

        for (int i = 0; i < dq.size(); i++) {
            // 기준 작업이 완료 되었을 때
            if (criteria <= 0)
                break;

            // 기준 작업 시간만큼 시간이 흐름
            dq[i] -= criteria;
        }

        while (!dq.empty()) {
            // 끝난 작업 갯수
            if (dq.front() <= 0) {
                ans++;
                dq.pop_front();

                // 큐가 비면 끝나버리기 때문에 마지막에 직접 추가
                if(dq.empty())
                    answer.push_back(ans);
            }
            else {
                answer.push_back(ans);
                break;
            }
        }
    }
    return answer;
}

int main() {
    solution({ 96,94 }, { 3,3});
    return 0;
}