#include <string>
#include <vector>
#include <iostream>
#include <limits.h>

using namespace std;

// 방문 여부
vector<int> visit(8, 0);
//초기화용
vector<int> clear(8, 0);
// 리스트
vector<vector<int>> list;

//최댓값
int MAX = INT_MIN;

void DFS(int cur, int idx, int num) {
    //최소 요구치 충족 못하면 빠꾸
    if (cur < list[idx][0])
        return;

    visit[idx] = 1;
    int piro = cur - list[idx][1];
    num++;

    // 최댓값 계속 갱신
    if (MAX < num)
        MAX = num;

    for (int i = 0; i < list.size(); i++) {
        // 한번도 안가본 던전이면
        if (visit[i] == 0) {
            DFS(piro, i, num++);
            // 갔다가 막혔으면 다시 돌아와서 재탐색 
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

        // 방문 기록 초기화
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