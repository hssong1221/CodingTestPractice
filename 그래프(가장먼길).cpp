#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

// ��������Ʈ
vector<vector<int>> adj(50001);
queue<int> q;

int BFS(int start, int n) {
    //�Ÿ� ������
    vector<int> v(n + 1, -1);
    v[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int n = q.front();
        q.pop();

        for (int i = 0; i < adj[n].size(); i++) {
            int next = adj[n][i];
            // �湮 ���� �ʾҴ� ���
            if (v[next] == -1) {
                // ���� ��忡�� ��ĭ ������ �ִ� ����
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

    // ��������Ʈ �����
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