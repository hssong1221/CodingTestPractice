#include <string>
#include <vector>
#include <iostream>

using namespace std;

void DFS(int n, vector<vector<int>> computers, int index);
int answer = 0;
vector<int> v(3, 0);

int solution(int n, vector<vector<int>> computers) {
    for (int i = 0; i < n; i++) {
        cout << i << endl;
        if (v[i] == 0) {
            DFS(n, computers, i);
            answer += 1;
        }
    }
    cout << "answer : " << answer << endl;

    return answer;
}

void DFS(int n, vector<vector<int>> computers, int index) {
    v[index] = 1;

    for (int k = 0; k < n; k++) {
        if (index == k)
            continue;

        if (computers[index][k] == 1 && v[k] == 0) {
            DFS(n, computers, k);
        }
    }
}



int main() {
    solution(3, { {1,1,0},{1,1,1},{0,1,1} });
    return 0;
}