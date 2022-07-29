#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
// 윤곽선 지도
vector<vector<int>> r(102, vector<int>(102, 0));
vector<vector<int>> r2(102, vector<int>(102, 0));

// 방문 여부와 도착순서
vector<vector<int>> visit(102, vector<int>(102, 0));
//큐
queue<pair<int, int>> q;
//상하좌우
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

    //상하좌우대각선
    int xx[8] = { 0,1,1,1,0,-1,-1,-1 };
    int yy[8] = { 1,1,0,-1,-1,-1,0,1 };

    // 크기를 2배를 하는 이유는 
    // 2중배열로 표현할 때 원래 크기대로 하면 좌표 한칸 사이를 표현할 때 
    // 윤곽선이 겹쳐서 판별이 불가능함 

    // 사각형 내부 좌표 따기
    for (int i = 0; i < rectangle.size(); i++) {
        for (int k = rectangle[i][0] * 2; k <= rectangle[i][2] * 2; k++) {
            for (int j = rectangle[i][1] * 2; j <= rectangle[i][3] * 2; j++) {
                r[k][j] = 1;
            }
        }
    }
    // 윤곽선이랑 닿는 부분만 남기기
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

    // 앞에서 2배크기로 한거 줄이기
    answer = (visit[itemX * 2][itemY * 2] - 1) / 2;
    return answer;
}



int main() {
    solution({ {1,1,7,4} ,{3,2,5,5},{4,3,6,9},{2,6,8,8} }, 1, 3, 7, 8);
    return 0;
}