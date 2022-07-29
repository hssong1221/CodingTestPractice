#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
// ������ ����
vector<vector<int>> r(102, vector<int>(102, 0));
vector<vector<int>> r2(102, vector<int>(102, 0));

// �湮 ���ο� ��������
vector<vector<int>> visit(102, vector<int>(102, 0));
//ť
queue<pair<int, int>> q;
//�����¿�
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,-1,1 };

void BFS(int cx, int cy) {
    visit[cx][cy] = 1;
    q.emplace(cx, cy);
    int n = 1;

    while (!q.empty()) {
        int tx = q.front().first;
        int ty = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = tx + dx[i];
            int ny = ty + dy[i];

            if (0 <= nx && nx < 102 && 0 <= ny && ny < 102) {
                if (visit[nx][ny] == 0 && r2[nx][ny] == 1) {
                    visit[nx][ny] = visit[tx][ty] + 1;
                    q.emplace(nx, ny);
                }
            }
        }
    }
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;

    //�����¿�밢��
    int xx[8] = { 0,1,1,1,0,-1,-1,-1 };
    int yy[8] = { 1,1,0,-1,-1,-1,0,1 };

    // ũ�⸦ 2�踦 �ϴ� ������ 
    // 2�߹迭�� ǥ���� �� ���� ũ���� �ϸ� ��ǥ ��ĭ ���̸� ǥ���� �� 
    // �������� ���ļ� �Ǻ��� �Ұ����� 

    // �簢�� ���� ��ǥ ����
    for (int i = 0; i < rectangle.size(); i++) {
        for (int k = rectangle[i][0] * 2; k <= rectangle[i][2] * 2; k++) {
            for (int j = rectangle[i][1] * 2; j <= rectangle[i][3] * 2; j++) {
                r[k][j] = 1;
            }
        }
    }
    // �������̶� ��� �κи� �����
    for (int i = 0; i < rectangle.size(); i++) {
        for (int k = rectangle[i][0] * 2; k <= rectangle[i][2] * 2; k++) {
            for (int j = rectangle[i][1] * 2; j <= rectangle[i][3] * 2; j++) {
                for (int a = 0; a < 8; a++) {
                    int tx = xx[a] + k;
                    int ty = yy[a] + j;
                    if (r[tx][ty] == 0) {
                        r2[k][j] = 1;
                        break;
                    }
                }
            }
        }
    }

    BFS(characterX * 2, characterY * 2);

    // �տ��� 2��ũ��� �Ѱ� ���̱�
    answer = (visit[itemX * 2][itemY * 2] - 1) / 2;
    return answer;
}



int main() {
    solution({ {1,1,7,4} ,{3,2,5,5},{4,3,6,9},{2,6,8,8} }, 1, 3, 7, 8);
    return 0;
}