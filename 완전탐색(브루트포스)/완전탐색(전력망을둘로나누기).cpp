#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <limits.h>

using namespace std;

// 인접행렬
vector<vector<int>> matrix(101, vector<int>(101, 0));
vector<vector<int>> temp(101, vector<int>(101, 0));

// 방문 여부
vector<int> clear(101, 0);
vector<int> visit(101, 0);
// 붙어있는 노드 갯수
int num = 0;

void DFS(int start) {
    // 방문
    visit[start] = 1;
    num++;
    // 현재 노드와 붙어있는 모든 노드 탐색
    for (int i = 0; i < temp[0].size(); i++) {
        // 붙어있는곳 아니면 넘어감
        if (temp[start][i] == 1 && visit[i] == 0)
            DFS(i);
    }
}

int solution(int n, vector<vector<int>> wires) {
    int answer = -1;
    int node = 0;
    // 인접행렬
    for (int i = 0; i < wires.size(); i++) {
        matrix[wires[i][0]][wires[i][1]] = 1;
        matrix[wires[i][1]][wires[i][0]] = 1;
    }

    int min = INT_MAX;
    // 연결 고리를 하나씩 끊어서 확인해보기
    for (int i = 0; i < wires.size(); i++) {
        // 초기화
        temp = matrix;
        num = 0;
        visit = clear;
        // 전체 노드 갯수를 알기위해
        if (i == 0) {
            DFS(wires[0][0]);
            node = num;

            temp = matrix;
            num = 0;
            visit = clear;
        }

        // 연결 끊기
        temp[wires[i][0]][wires[i][1]] = 0;
        temp[wires[i][1]][wires[i][0]] = 0;

        DFS(wires[0][0]);

        //잘린 양쪽의 갯수 차이
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