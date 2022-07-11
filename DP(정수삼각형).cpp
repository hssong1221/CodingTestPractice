#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;

    vector<int>::iterator it;
    int k;
    for (int i = 1; i < triangle.size(); i++) {
        for (it = triangle[i].begin(), k = 0; it != triangle[i].end(); it++, k++) {
            //맨 왼쪽은 윗라인 왼쪽으로 통해서만 올수 있음
            if (it == triangle[i].begin()) {
                triangle[i][k] += triangle[i - 1][k];
                continue;
            }
            //맨 오른쪽은 윗라인 맨 오른쪽으로 통해서만 올수 있음 (end()는 끝나고 다음 칸)
            if (it == triangle[i].end() - 1) {
                triangle[i][k] += triangle[i - 1][k - 1];
                continue;
            }

            //가운데는 바로 위 양쪽중에서 큰거 고름
            if (triangle[i - 1][k - 1] < triangle[i - 1][k])
                triangle[i][k] += triangle[i - 1][k];
            else
                triangle[i][k] += triangle[i - 1][k - 1];
        }
    }

    // 맨 밑에줄까지 싹다 더해서 그중에 제일 큰거
    answer = *max_element(triangle[triangle.size() - 1].begin(), triangle[triangle.size() - 1].end());
    
    cout << answer;
    return answer;
}

int main() {
    solution({ {7},{3, 8},{8, 1, 0},{2, 7, 4, 4},{4, 5, 2, 6, 5} });
    return 0;
}