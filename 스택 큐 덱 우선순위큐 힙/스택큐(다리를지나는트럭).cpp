#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;

    vector<int> t = truck_weights;
    queue<int> bridge;  // 다리 상태 (뒤에서 들어와서 앞으로 나감)
    int i = 0;  // 트럭 순서
    int total = 0; // 현재 다리 무게

    // 트럭이 다리 건너기 시작
    while (true) {
        // 마지막 트럭일 때
        if (i == t.size()) {
            answer += bridge_length;
            break;
        }
        // 경과 시간
        answer++;

        //다리에 트럭으로 꽉 찼을 때 맨 앞에서 트럭 나감
        if (bridge.size() == bridge_length) {
            total -= bridge.front();
            bridge.pop();
        }

        // 다리위 트럭 무게와 들어올 트럭 무게 합이 한계 무게보다 작을 때 트럭 진입
        if (total + t[i] <= weight) {
            total += t[i];
            bridge.push(t[i]);
            i += 1; // 다음 트럭
        }
        // 못 들어오면 대기
        else {
            bridge.push(0);
        }
    }

    cout << answer;
    return answer;
}

int main() {
    solution(2, 10, { 7,4,5,6 });
    return 0;
}