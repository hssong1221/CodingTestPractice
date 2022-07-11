#include <string>
#include <vector>
#include <iostream>

using namespace std;

void DFS(vector<int> numbers, int target, int sum, int i);
int answer = 0;

int solution(vector<int> numbers, int target) {

    //DFS
    DFS(numbers, target, 0, 0);

    cout << answer;
    return answer;
}

void DFS(vector<int> numbers, int target, int sum, int i) {
    // ���� ���� ������ ������
    if (i == numbers.size()) {
        if (sum == target)
            answer++;

        return;
    }
    //�ƴϸ� ���غ��ų� �����ų�
    DFS(numbers, target, sum + numbers[i], i + 1);
    DFS(numbers, target, sum - numbers[i], i + 1);
}

int main() {
    solution({ 1,1,1,1,1 }, 3);
    return 0;
}