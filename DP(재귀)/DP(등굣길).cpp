#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;

    // 문제가 행렬을 거꾸로 표현해 놨음 ㅡㅡ
    vector<vector<int>> v(101, vector<int>(101, 0));

    v[1][1] = 1;
    for (int i = 0; i < puddles.size(); i++)
        v[puddles[i][1]][puddles[i][0]] = -1;

    for (int i = 1; i <= n; i++) {
        for (int k = 1; k <= m; k++) {
            // 연못 제외
            if (v[i][k] == -1)
                continue;
            int up = 0;
            int left = 0;

            // 왼쪽에 연못이 있지 않다면
            if (v[i][k - 1] != -1)
                left = v[i][k - 1];
            // 위쪽에 연못이 없다면
            if (v[i - 1][k] != -1)
                up = v[i - 1][k];

            // v[1][1]부터 시작해서 더하기 
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