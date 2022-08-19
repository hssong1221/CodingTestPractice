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
            //�� ������ ������ �������� ���ؼ��� �ü� ����
            if (it == triangle[i].begin()) {
                triangle[i][k] += triangle[i - 1][k];
                continue;
            }
            //�� �������� ������ �� ���������� ���ؼ��� �ü� ���� (end()�� ������ ���� ĭ)
            if (it == triangle[i].end() - 1) {
                triangle[i][k] += triangle[i - 1][k - 1];
                continue;
            }

            //����� �ٷ� �� �����߿��� ū�� ��
            if (triangle[i - 1][k - 1] < triangle[i - 1][k])
                triangle[i][k] += triangle[i - 1][k];
            else
                triangle[i][k] += triangle[i - 1][k - 1];
        }
    }

    // �� �ؿ��ٱ��� �ϴ� ���ؼ� ���߿� ���� ū��
    answer = *max_element(triangle[triangle.size() - 1].begin(), triangle[triangle.size() - 1].end());
    
    cout << answer;
    return answer;
}

int main() {
    solution({ {7},{3, 8},{8, 1, 0},{2, 7, 4, 4},{4, 5, 2, 6, 5} });
    return 0;
}