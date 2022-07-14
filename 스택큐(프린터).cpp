#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <deque>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    //이름을 간단하게
    int lo = location;
    deque<int> dq;
    for (auto p : priorities)
        dq.push_back(p);

    while (true) {
        // 가장 높은 우선순위 찾기
        int max = *max_element(dq.begin(), dq.end());
        int temp = 0;

        // 앞에서부터 찾는데 우선순위 딸리면 뒤로 보냄
        if (dq.front() < max) {
            temp = dq.front();
            dq.pop_front();
            dq.push_back(temp);

            // 숫자 위치가 바뀜에 따라서 location값도 같이 바꿔줌
            if (lo == 0)
                lo += dq.size() - 1;
            else
                lo--;
        }
        // 우선순위 가장 높은 것
        else if (dq.front() == max) {
            dq.pop_front();
            answer++;

            // 목표 location 찾았을 때
            if (lo == 0)
                break;
            else
                lo--;
        }
    }
    cout << answer;
    return answer;
}

int main() {
    solution({ 1,1,9,1,1,1 }, 0);

    return 0;
}