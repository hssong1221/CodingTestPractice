#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

/// <summary>
/// �켱����ť�� ���� ���� ��� O(log2N)�� �׷��� ���ڰ� Ŀ���� �迭�̳� ���Ḯ��Ʈ���� ������
/// </summary>

int solution(vector<int> scoville, int K) {
    int answer = -1;    // ���� Ƚ��

    // �켱���� ť�� int���� ������������ greater ����� ��������
    priority_queue<int, vector<int>, greater<int>> pq;

    // �־��ָ� �˾Ƽ� ���ĵ�
    for (auto i : scoville)
        pq.push(i);

    int a = 0;
    int temp1 = 0;
    int temp2 = 0;

    for (int i = 0; i < scoville.size(); i++) {
        // ���ٰ� �Ѱ� �������� ����ġ �Ѵ��� �ȳѴ��� Ȯ���� ��
        if (pq.size() == 1) {
            if (pq.top() >= K)
                answer = i;
            break;
        }

        a = 0;              // ���� ����
        temp1 = pq.top();   // ���� �ȸſ��
        pq.pop();       
        temp2 = pq.top();   // 2��°�� �ȸſ��
        pq.pop();

        // �� �� 2���� ��� ����ġ�� ������ �� �ڷδ� �Ⱥ��� ��
        if (temp1 >= K && temp2 >= K) {
            answer = i;
            break;
        }

        a = temp1 + (temp2 * 2);    // ��� �ٽ� �־���
        pq.push(a);
    }
    cout << answer;
    return answer;
}

int main() {
    solution({ 1,2,3,9,10,12 }, 7);
    return 0;
}