#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;

    vector<int> t = truck_weights;
    queue<int> bridge;  // �ٸ� ���� (�ڿ��� ���ͼ� ������ ����)
    int i = 0;  // Ʈ�� ����
    int total = 0; // ���� �ٸ� ����

    // Ʈ���� �ٸ� �ǳʱ� ����
    while (true) {
        // ������ Ʈ���� ��
        if (i == t.size()) {
            answer += bridge_length;
            break;
        }
        // ��� �ð�
        answer++;

        //�ٸ��� Ʈ������ �� á�� �� �� �տ��� Ʈ�� ����
        if (bridge.size() == bridge_length) {
            total -= bridge.front();
            bridge.pop();
        }

        // �ٸ��� Ʈ�� ���Կ� ���� Ʈ�� ���� ���� �Ѱ� ���Ժ��� ���� �� Ʈ�� ����
        if (total + t[i] <= weight) {
            total += t[i];
            bridge.push(t[i]);
            i += 1; // ���� Ʈ��
        }
        // �� ������ ���
        else {
            bridge.push(0);
        }
    }

    cout << answer;
    return answer;
}

int main() {
    solution(2, 10, { 7,4,5,6 });
    return 0;
}