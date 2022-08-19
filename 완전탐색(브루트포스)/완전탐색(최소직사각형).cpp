#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;

    vector<int> garo;
    vector<int> sero;
    int garomax = 0;
    int seromax = 0;
    for (int i = 0; i < sizes.size(); i++) {
        // ���� ���� ���� �����ֱⰡ �ʿ��ϴ�
        // ���� ���̰� ���� ���̺��� �� ��
        if (sizes[i][0] > sizes[i][1]) {
            garo.push_back(sizes[i][0]);
            sero.push_back(sizes[i][1]);
        }
        else {
            garo.push_back(sizes[i][1]);
            sero.push_back(sizes[i][0]);
        }
    }
    // �� �߿� ���� ū�͸� ��� ���
    garomax = *max_element(garo.begin(), garo.end());
    seromax = *max_element(sero.begin(), sero.end());
    answer = garomax * seromax;

    cout << answer;
    return answer;
}

int main() {
    solution({ {10,7},{12,3},{8,15},{14,7},{5,15} });
    return 0;
}
