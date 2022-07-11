#include <string>
#include <vector>
#include <queue>
#include <iostream>
//#include <utility>

using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    // ��û�ð� ��������, �۾��ð� �������� ���� 
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // �۾��ð� ��������, ��û�ð� �������� ����
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> list;

    int time = 0;

    for(int i = 0; i < jobs.size(); i++)
        pq.emplace(jobs[i][0], jobs[i][1]);


    // ù ��° �۾�
    time += pq.top().first + pq.top().second;
    answer = pq.top().second;
    pq.pop();
    cout << answer << endl;

    // �۾� ��û�� �� ����Ǹ� ��
    while (!pq.empty()) {
        // ���� �۾��� ����Ǳ� ���� ��û�Ȱ� ã��
        while (!pq.empty()) {
            if (pq.top().first <= time) {
                // �� �߿��� ���� ���� �����°� ������ ���� �ϱ�
                list.emplace(pq.top().second, pq.top().first);
                pq.pop();
            }
            else
                break;
        }
        // �۾��ð� ���̰� ������ �Ҷ�
        if (list.empty()) {
            time++;
            continue;
        }

        time += list.top().first;
        answer = answer +  (time - list.top().second);
        list.pop();
        // ���� �۾��� ���� �۾� ����Ʈ�� �ٽ� �ֱ�
        for (int i = 0; i < list.size(); i++) {
            pq.emplace(list.top().second, list.top().first);
            list.pop();
        }

        cout << answer << endl;
    }
    answer /= jobs.size();
    cout << answer << endl;
    return answer;
}


int main() {
    solution({ {0,3},{4,1} });
    return 0;
}