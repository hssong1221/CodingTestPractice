#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
// ������ ����
vector<vector<int>> r(50, vector<int>(50, 0));
vector<vector<int>> r2(50, vector<int>(50, 0));

// �湮 ����
vector<vector<int>> visit(50, vector<int>(50, 0));
//ť
queue<pair<int, int>> q;

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;

    //�����¿�밢��
    int xx[8] = { 0,1,1,1,0,-1,-1,-1 };
    int yy[8] = { 1,1,0,-1,-1,-1,0,1 };

    // �簢�� ���� ��ǥ ����
    for (int i = 0; i < rectangle.size(); i++) {
        for (int k = rectangle[i][0]; k < rectangle[i][2]; k++) {
            for (int j = rectangle[i][1]; j < rectangle[i][3]; j++) {
                r[k][j] = 1;
            }
        }
    }

    // �������̶� ��� �κи� �����
    for (int i = 0; i < rectangle.size(); i++) {
        for (int k = rectangle[i][0]; k < rectangle[i][2]; k++) {
            for (int j = rectangle[i][1]; j < rectangle[i][3]; j++) {
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
    
    

    
    for (auto &a : r2) {
        for (auto b : a) {
            cout << b << " ";
        }
        cout << endl;
    }
    return answer;
}

void BFS(int cx, int cy, int ix, int iy) {
    

}

int main() {
    solution({ {1,1,7,4} ,{3,2,5,5},{4,3,6,9},{2,6,8,8} }, 1, 3, 7, 8);
    return 0;
}