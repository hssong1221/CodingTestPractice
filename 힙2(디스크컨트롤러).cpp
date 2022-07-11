#include <string>
#include <vector>
#include <queue>
#include <iostream>
//#include <utility>

using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    // 요청시간 오름차순, 작업시간 오름차순 정렬 
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // 작업시간 오름차순, 요청시간 오름차순 정렬
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> list;

    int time = 0;

    for(int i = 0; i < jobs.size(); i++)
        pq.emplace(jobs[i][0], jobs[i][1]);


    // 첫 번째 작업
    time += pq.top().first + pq.top().second;
    answer = pq.top().second;
    pq.pop();
    cout << answer << endl;

    // 작업 요청이 다 수행되면 끝
    while (!pq.empty()) {
        // 현재 작업이 종료되기 전에 요청된거 찾기
        while (!pq.empty()) {
            if (pq.top().first <= time) {
                // 그 중에서 제일 빨리 끝나는게 앞으로 오게 하기
                list.emplace(pq.top().second, pq.top().first);
                pq.pop();
            }
            else
                break;
        }
        // 작업시간 사이가 띄엄띄엄 할때
        if (list.empty()) {
            time++;
            continue;
        }

        time += list.top().first;
        answer = answer +  (time - list.top().second);
        list.pop();
        // 못한 작업은 원래 작업 리스트에 다시 넣기
        for (int i = 0; i < list.size(); i++) {
            pq.emplace(list.top().second, list.top().first);
            list.pop();
        }

        cout << answer << endl;
    }
    answer /= jobs.size();
    cout << answer << endl;
    return answer;
}


int main() {
    solution({ {0,3},{4,1} });
    return 0;
}