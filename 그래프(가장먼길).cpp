#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

// 인접리스트
vector<vector<int>> adj(50001);
queue<int> q;

int BFS(int start, int n) {
    //거리 측정용
    vector<int> v(n + 1, -1);
    v[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int n = q.front();
        q.pop();

        for (int i = 0; i < adj[n].size(); i++) {
            int next = adj[n][i];
            // 방문 하지 않았던 노드
            if (v[next] == -1) {
                // 현재 노드에서 한칸 떨어져 있는 거임
                v[next] = v[n] + 1;
                q.push(next);
            }
        }
    }
    int temp = 0;
    int max = *max_element(v.begin(), v.end());
    for (auto i : v) {
        if (max == i)
            temp++;
    }
    return temp;
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;

    // 인접리스트 만들기
    for (int i = 0; i < edge.size(); i++) {
        adj[edge[i][0]].push_back(edge[i][1]);
        adj[edge[i][1]].push_back(edge[i][0]);
    }
    // BFS
    answer = BFS(1, n);
    cout << answer;
    return answer;
}

int main() {
    solution( 6, { {3,6},{4,3},{3,2},{1,3},{1,2},{2,4},{5,2} });
    return 0;
}