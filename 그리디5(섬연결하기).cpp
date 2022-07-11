#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//MST를 구현하는 프림 알고리즘
int solution(int n, vector<vector<int>> costs) {
    int answer = 0;

    //인접행렬
    vector<vector<int>> g(n, vector<int>(n));
    for (int i = 0; i < costs.size(); i++) {
        g[costs[i][0]][costs[i][1]] = costs[i][2];
        g[costs[i][1]][costs[i][0]] = costs[i][2];
    }
    //방문노드
    vector<int> v;
    //방문노드 x
    vector<int> u;

    //첫번째 정점넣고 시작
    v.push_back(0);
    //아직 안 간 곳
    for (int i = 1; i < n; i++)
        u.push_back(i);

    // 방문 정점 개수만큼
    for (int i = 1; i < n; i++) { 
        int min = INT_MAX;
        int mindex = 0;
        
        // v 순회 
        for (int j = 0; j < i; j++) {
            // u 순회
            for (int k = 0; k < n - i; k++) {
                // 인접한 것이 있는지, 있다면 최소값인지
                if (g[v[j]][u[k]] > 0 && min > g[v[j]][u[k]])
                {
                    min = g[v[j]][u[k]];
                    mindex = k;
                }
            }
        }
        // 방문한거 넣고 지우기
        v.push_back(u[mindex]);
        u.erase(u.begin() + mindex);
        answer += min;
    }
    return answer;
}

int main() {
    solution();
    return 0;
}