#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

/// <summary>
/// 우선순위큐는 삽입 삭제 모두 O(log2N)임 그래서 숫자가 커지면 배열이나 연결리스트보다 빠르다
/// </summary>

int solution(vector<int> scoville, int K) {
    int answer = -1;    // 섞은 횟수

    // 우선순위 큐는 int형은 내림차순정렬 greater 해줘야 오름차순
    priority_queue<int, vector<int>, greater<int>> pq;

    // 넣어주면 알아서 정렬됨
    for (auto i : scoville)
        pq.push(i);

    int a = 0;
    int temp1 = 0;
    int temp2 = 0;

    for (int i = 0; i < scoville.size(); i++) {
        // 섞다가 한개 남았을때 기준치 넘는지 안넘는지 확인후 답
        if (pq.size() == 1) {
            if (pq.top() >= K)
                answer = i;
            break;
        }

        a = 0;              // 섞은 음식
        temp1 = pq.top();   // 제일 안매운거
        pq.pop();       
        temp2 = pq.top();   // 2번째로 안매운거
        pq.pop();

        // 맨 앞 2개가 모두 기준치를 넘으면 그 뒤로는 안봐도 됨
        if (temp1 >= K && temp2 >= K) {
            answer = i;
            break;
        }

        a = temp1 + (temp2 * 2);    // 섞어서 다시 넣어줌
        pq.push(a);
    }
    cout << answer;
    return answer;
}

int main() {
    solution({ 1,2,3,9,10,12 }, 7);
    return 0;
}