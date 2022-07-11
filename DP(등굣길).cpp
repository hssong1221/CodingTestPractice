#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;

    // ������ ����� �Ųٷ� ǥ���� ���� �Ѥ�
    vector<vector<int>> v(101, vector<int>(101, 0));

    v[1][1] = 1;
    for (int i = 0; i < puddles.size(); i++)
        v[puddles[i][1]][puddles[i][0]] = -1;

    for (int i = 1; i <= n; i++) {
        for (int k = 1; k <= m; k++) {
            // ���� ����
            if (v[i][k] == -1)
                continue;
            int up = 0;
            int left = 0;

            // ���ʿ� ������ ���� �ʴٸ�
            if (v[i][k - 1] != -1)
                left = v[i][k - 1];
            // ���ʿ� ������ ���ٸ�
            if (v[i - 1][k] != -1)
                up = v[i - 1][k];

            // v[1][1]���� �����ؼ� ���ϱ� 
            v[i][k] += (left + up) % 1000000007;

            cout << "i : " << i << " k : " << k << " " << v[i][k] << endl;
        }
    }
    answer = v[n][m];
    cout << answer;
    return answer;
}

int main() {
    solution(4, 3, { { 2,2 } });
    return 0;
}