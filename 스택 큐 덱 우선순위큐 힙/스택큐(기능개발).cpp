#include <string>
#include <vector>
#include <iostream>
#include <deque>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    deque<int> dq;

    for (int i = 0; i < progresses.size(); i++) {
        // ���� ����� (100�Ǹ� �ٷ� �����ϱ� ������ �۾� �ϼ��� ������ �ȉ� �׷��� 99���� ������)
        int t = (99 - progresses[i]);

        // �۾� �Ϸ���� ���� ��¥
        dq.push_back((t / speeds[i]) + 1);
    }

    while (!dq.empty()) {
        int ans = 0;
        int criteria = dq.front(); // ����

        for (int i = 0; i < dq.size(); i++) {
            // ���� �۾��� �Ϸ� �Ǿ��� ��
            if (criteria <= 0)
                break;

            // ���� �۾� �ð���ŭ �ð��� �帧
            dq[i] -= criteria;
        }

        while (!dq.empty()) {
            // ���� �۾� ����
            if (dq.front() <= 0) {
                ans++;
                dq.pop_front();

                // ť�� ��� ���������� ������ �������� ���� �߰�
                if(dq.empty())
                    answer.push_back(ans);
            }
            else {
                answer.push_back(ans);
                break;
            }
        }
    }
    return answer;
}

int main() {
    solution({ 96,94 }, { 3,3});
    return 0;
}