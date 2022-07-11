#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;

    queue<int> bridge;
    vector<int> t;
    t = truck_weights;
    int i = 0;
    int total = 0;

    while (true) {
        if (i == t.size()) {
            answer += bridge_length;
            break;
        }
        answer++;

        if (bridge.size() == bridge_length) {
            total -= bridge.front();
            bridge.pop();
        }

        if (total + t[i] <= weight) {
            total += t[i];
            bridge.push(t[i++]);
        }
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