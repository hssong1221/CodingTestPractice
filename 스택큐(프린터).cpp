#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <deque>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    //�̸��� �����ϰ�
    int lo = location;
    deque<int> dq;
    for (auto p : priorities)
        dq.push_back(p);

    while (true) {
        // ���� ���� �켱���� ã��
        int max = *max_element(dq.begin(), dq.end());
        int temp = 0;

        // �տ������� ã�µ� �켱���� ������ �ڷ� ����
        if (dq.front() < max) {
            temp = dq.front();
            dq.pop_front();
            dq.push_back(temp);

            // ���� ��ġ�� �ٲ� ���� location���� ���� �ٲ���
            if (lo == 0)
                lo += dq.size() - 1;
            else
                lo--;
        }
        // �켱���� ���� ���� ��
        else if (dq.front() == max) {
            dq.pop_front();
            answer++;

            // ��ǥ location ã���� ��
            if (lo == 0)
                break;
            else
                lo--;
        }
    }
    cout << answer;
    return answer;
}

int main() {
    solution({ 1,1,9,1,1,1 }, 0);

    return 0;
}