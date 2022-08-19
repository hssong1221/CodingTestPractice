#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <limits.h>

using namespace std;

// �������
vector<vector<int>> matrix(101, vector<int>(101, 0));
vector<vector<int>> temp(101, vector<int>(101, 0));

// �湮 ����
vector<int> clear(101, 0);
vector<int> visit(101, 0);
// �پ��ִ� ��� ����
int num = 0;

void DFS(int start) {
    // �湮
    visit[start] = 1;
    num++;
    // ���� ���� �پ��ִ� ��� ��� Ž��
    for (int i = 0; i < temp[0].size(); i++) {
        // �پ��ִ°� �ƴϸ� �Ѿ
        if (temp[start][i] == 1 && visit[i] == 0)
            DFS(i);
    }
}

int solution(int n, vector<vector<int>> wires) {
    int answer = -1;
    int node = 0;
    // �������
    for (int i = 0; i < wires.size(); i++) {
        matrix[wires[i][0]][wires[i][1]] = 1;
        matrix[wires[i][1]][wires[i][0]] = 1;
    }

    int min = INT_MAX;
    // ���� ���� �ϳ��� ��� Ȯ���غ���
    for (int i = 0; i < wires.size(); i++) {
        // �ʱ�ȭ
        temp = matrix;
        num = 0;
        visit = clear;
        // ��ü ��� ������ �˱�����
        if (i == 0) {
            DFS(wires[0][0]);
            node = num;

            temp = matrix;
            num = 0;
            visit = clear;
        }

        // ���� ����
        temp[wires[i][0]][wires[i][1]] = 0;
        temp[wires[i][1]][wires[i][0]] = 0;

        DFS(wires[0][0]);

        //�߸� ������ ���� ����
        int result = (node - num) - num;
        result = abs(result);

        if (result < min)
           min = result;
    }
    answer = min;
    return answer;
}



int main() {
    solution(4, { {1,2},{2,3},{3,4} });
    return 0;
}