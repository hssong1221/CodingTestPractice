#include <string>
#include <vector>
#include <iostream>
#include <limits.h>

using namespace std;

// �湮 ����
vector<int> visit(8, 0);
//�ʱ�ȭ��
vector<int> clear(8, 0);
// ����Ʈ
vector<vector<int>> list;

//�ִ�
int MAX = INT_MIN;

void DFS(int cur, int idx, int num) {
    //�ּ� �䱸ġ ���� ���ϸ� ����
    if (cur < list[idx][0])
        return;

    visit[idx] = 1;
    int piro = cur - list[idx][1];
    num++;

    // �ִ� ��� ����
    if (MAX < num)
        MAX = num;

    for (int i = 0; i < list.size(); i++) {
        // �ѹ��� �Ȱ��� �����̸�
        if (visit[i] == 0) {
            DFS(piro, i, num++);
            // ���ٰ� �������� �ٽ� ���ƿͼ� ��Ž�� 
            visit[i] = 0;
            num--;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    list = dungeons;

    for (int i = 0; i < dungeons.size(); i++) {
        DFS(k, i, 0);

        // �湮 ��� �ʱ�ȭ
        visit = clear;
    }
    answer = MAX;
    cout << answer;

    return answer;
}



int main() {
    solution(80, { {80,20},{50,40},{30,10} });
    return 0;
}