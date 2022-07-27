#include<vector>
#include <queue>
#include <iostream>

using namespace std;

// 지도
vector<vector<int>> m;
//방문 여부
vector<vector<int>> visit(101, vector<int>(101, 0));
//방문 순서를 알면 최단 거리를 알수있음
vector<vector<int>> len(101, vector<int>(101, 0));
//큐
queue < pair<int, int> > q;
//상하좌우
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,-1,1 };
// 맵 크기
int N, M;
// 정답
int answer = -1;

void BFS(int x, int y) {
    visit[x][y] = 1;
    q.emplace(x, y);

    while (!q.empty()) {
        int tx = q.front().first;
        int ty = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = tx + dx[i];
            int ny = ty + dy[i];

            if (0 <= nx && nx < N && 0 <= ny && ny < M) {
                if (visit[nx][ny] == 0 && m[nx][ny] == 1) { //길 이지만 아직 안 가본곳
                    visit[nx][ny] = 1;
                    len[nx][ny] = len[tx][ty] + 1;
                    q.emplace(nx, ny);
                }
            }
        }
    }
}

int solution(vector<vector<int> > maps){
    m = maps;
    N = maps.size();
    M = maps[0].size();


    BFS(0, 0);

    // 목적지 도달
    if(len[N - 1][M - 1] != 0)
        answer = len[N - 1][M - 1] + 1;
    
    cout << answer;
    return answer;
}
// 산술 오버플로란 무엇인가?

int main() {
    solution({ {1,0,1,1,1},{1,0,1,0,1},{1,0,1,1,1},{1,1,1,0,1},{0,0,0,0,1} });
    return 0;
}