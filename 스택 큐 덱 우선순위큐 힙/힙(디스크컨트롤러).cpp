#include <string>
#include <vector>
#include <queue>
#include <iostream>
//#include <utility>

using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    // 요청시간 오름차순, 작업시간 오름차순 정렬 
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> seq;

    // 작업시간 오름차순, 요청시간 오름차순 정렬
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> work;

    int time = 0;   // 작업에 소요된 시간

    // emplace를 쓰면 알아서 슉슉 들어감
    for (int i = 0; i < jobs.size(); i++)
        seq.emplace(jobs[i][0], jobs[i][1]);


    // 첫 번째 작업은 맨 앞에오면 무조건 실행
    time += seq.top().first + seq.top().second;
    answer = seq.top().second; //(0+작업시간)
    seq.pop();

    // 작업 요청이 다 수행되면 끝
    while (!seq.empty()) {
        // 현재 작업이 종료되기 전에 요청된거 찾기
        while (!seq.empty()) {
            if (seq.top().first <= time) {
                // 그 중에서 제일 빨리 끝나는게 앞으로 오게 하기
                work.emplace(seq.top().second, seq.top().first);
                seq.pop();
            }
            else
                break;
        }
        // 작업시간 사이가 연속적이지 않고 띄엄띄엄 할때
        if (work.empty()) {
            time++;
            continue;
        }

        time += work.top().first;
        answer = answer + (time - work.top().second); // 현재시간에서 요청시간 빼서 작업소요시간 구하기
        work.pop();
        // 못한 작업은 원래 작업 리스트에 다시 넣기
        for (int i = 0; i < work.size(); i++) {
            seq.emplace(work.top().second, work.top().first);
            work.pop();
        }
    }
    answer /= jobs.size();
    cout << answer;
    return answer;
}


int main() {
    solution({ {0,3},{4,1} });
    return 0;
}