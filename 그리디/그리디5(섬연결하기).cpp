#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//MST�� �����ϴ� ���� �˰���
int solution(int n, vector<vector<int>> costs) {
    int answer = 0;

    //�������
    vector<vector<int>> g(n, vector<int>(n));
    for (int i = 0; i < costs.size(); i++) {
        g[costs[i][0]][costs[i][1]] = costs[i][2];
        g[costs[i][1]][costs[i][0]] = costs[i][2];
    }
    //�湮���
    vector<int> v;
    //�湮��� x
    vector<int> u;

    //ù��° �����ְ� ����
    v.push_back(0);
    //���� �� �� ��
    for (int i = 1; i < n; i++)
        u.push_back(i);

    // �湮 ���� ������ŭ
    for (int i = 1; i < n; i++) { 
        int min = INT_MAX;
        int mindex = 0;
        
        // v ��ȸ 
        for (int j = 0; j < i; j++) {
            // u ��ȸ
            for (int k = 0; k < n - i; k++) {
                // ������ ���� �ִ���, �ִٸ� �ּҰ�����
                if (g[v[j]][u[k]] > 0 && min > g[v[j]][u[k]])
                {
                    min = g[v[j]][u[k]];
                    mindex = k;
                }
            }
        }
        // �湮�Ѱ� �ְ� �����
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