#include <string>
#include <vector>
#include <queue>
#include <iostream>
//#include <utility>

using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    // ��û�ð� ��������, �۾��ð� �������� ���� 
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> seq;

    // �۾��ð� ��������, ��û�ð� �������� ����
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> work;

    int time = 0;   // �۾��� �ҿ�� �ð�

    // emplace�� ���� �˾Ƽ� ���� ��
    for (int i = 0; i < jobs.size(); i++)
        seq.emplace(jobs[i][0], jobs[i][1]);


    // ù ��° �۾��� �� �տ����� ������ ����
    time += seq.top().first + seq.top().second;
    answer = seq.top().second; //(0+�۾��ð�)
    seq.pop();

    // �۾� ��û�� �� ����Ǹ� ��
    while (!seq.empty()) {
        // ���� �۾��� ����Ǳ� ���� ��û�Ȱ� ã��
        while (!seq.empty()) {
            if (seq.top().first <= time) {
                // �� �߿��� ���� ���� �����°� ������ ���� �ϱ�
                work.emplace(seq.top().second, seq.top().first);
                seq.pop();
            }
            else
                break;
        }
        // �۾��ð� ���̰� ���������� �ʰ� ������ �Ҷ�
        if (work.empty()) {
            time++;
            continue;
        }

        time += work.top().first;
        answer = answer + (time - work.top().second); // ����ð����� ��û�ð� ���� �۾��ҿ�ð� ���ϱ�
        work.pop();
        // ���� �۾��� ���� �۾� ����Ʈ�� �ٽ� �ֱ�
        for (int i = 0; i < work.size(); i++) {
            seq.emplace(work.top().second, work.top().first);
            work.pop();
        }
    }
    answer /= jobs.size();
    cout << answer;
    return answer;
}


int main() {
    solution({ {0,3},{4,1} });
    return 0;
}