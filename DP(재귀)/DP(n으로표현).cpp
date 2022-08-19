#include <string>
#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int solution(int N, int number) {
    int answer = -1;

    unordered_set<int> set[8]; // ����x �ߺ�x 

    int temp = 0;
    for (int i = 0; i < 8; i++) {
        temp = temp * 10 + N;       // N, NN, NNN ... NNNNNNNN����
        set[i].insert(temp);
    }

    //ex) set[1]�϶� set[0] (+-*/) set[1], set[1] (+-*/) set[0] 
    //ex) set[2]�϶� set[0] (+-*/) set[2], set[1] (+-*/) set[1], set[2] (+-*/) set[0] 
    for (int i = 1; i < 8; ++i) {
        for (int j = 0; j < i; ++j) {
            for (auto a : set[j]) {
                for (auto b : set[i - j - 1]) {
                    set[i].insert(a + b);
                    set[i].insert(a - b);
                    set[i].insert(a * b);
                    if (b != 0)
                        set[i].insert(a / b);
                }
            }
        }
    }
    
    //set[i]�ȿ� number�� �ִ��� �տ������� Ȯ���ؼ� �ּڰ�ã��
    for (int i = 0; i < 8; i++) {
        if (set[i].find(number) != set[i].end()) {
            answer = i + 1;
            break;
        }
    }
    cout << answer;
    return answer;
}

int main() {
    solution(5, 12);
    return 0;
}