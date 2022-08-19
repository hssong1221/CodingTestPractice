#include <string>
#include <vector>
#include <iostream>

using namespace std;

int answer = 0;
vector<int> n;

void DFS(int target, int sum, int i) {
    // ���� ���� ������ ������
    if (i == n.size()) {
        if (sum == target)
            answer++;

        return;
    }
    //�ƴϸ� ���غ��ų� �����ų�
    DFS(target, sum + n[i], i + 1);
    DFS(target, sum - n[i], i + 1);
}

int solution(vector<int> numbers, int target) {
    n = numbers;

    //DFS
    DFS(target, 0, 0);

    cout << answer;
    return answer;
}



int main() {
    solution({ 1,1,1,1,1 }, 3);
    return 0;
}