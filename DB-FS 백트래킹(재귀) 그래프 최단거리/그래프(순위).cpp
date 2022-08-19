#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 플로이드 워셜 알고리즘
// 모든 경로에서 최단거리를 구하는 알고리즘
// 어떤 노드 n을 거쳤을 때와 안거쳤을 때 가중치를 비교해서 더 짧은 거리를 계속 갱신함
// ex) 원래 i->j 가 i->k->j 보다 길면 갱신
// 문제에서는 (i, j) (j, k) 면 i는 k를 이긴거임

int solution(int n, vector<vector<int>> results) {
    int answer = 0;

    // 인접행렬 비슷하게 이기면 1 지면 0 해주기
    vector<vector<int>> rank(102 , vector<int>(102 , 0));
    for (int i = 0; i < results.size(); i++) {
        rank[results[i][0]][results[i][1]] = 1;
        rank[results[i][1]][results[i][0]] = -1;
    }
    
    // 1부터 시작
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                // 대결 결과가 없어서 0인곳중에서 간접적으로 알수 있는것 찾기
                if (rank[j][k] == 0) {
                    if (rank[j][i] == 1 && rank[i][k] == 1) 
                        rank[j][k] = 1;
                    else if (rank[j][i] == -1 && rank[i][k] == -1)
                        rank[j][k] = -1;
                }
            }
        }
    }

    // 자기 자신 빼고 전부 이기거나 진게 확정되면 순위가 정해짐
    for (int i = 1; i <= n; i++) {
        int temp = 0;
        for (int j = 1; j <= n; j++) {
            cout << rank[i][j] << " ";
            if (rank[i][j] == 0)
                temp++;
        }
        cout << endl;
        if (temp == 1)
            answer++;
    }

    cout << answer;
    return answer;
}

int main() {
    solution(5, { {1,2},{4,5},{3,4},{2,3} });
    return 0;
}