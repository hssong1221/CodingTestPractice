#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = -1;

    vector<int> s = scoville;
    sort(s.begin(), s.end());

    priority_queue<int, vector<int>, greater<int>> pq;

    for (auto i : s)
        pq.push(i);

    int a = 0;
    int temp1 = 0;
    int temp2 = 0;

    for (int i = 0; i < s.size(); i++) {
        if (pq.size() == 1) {
            if (pq.top() >= K)
                answer = i;
            break;
        }

        a = 0;
        temp1 = pq.top();
        pq.pop();
        temp2 = pq.top();
        pq.pop();

        if (temp1 >= K && temp2 >= K) {
            answer = i;
            break;
        }

        a = temp1 + (temp2 * 2);
        pq.push(a);

    }
    cout << answer;
    return answer;
}

int main() {
    solution({ 1,2,3,9,10,12 }, 7);
    return 0;
}