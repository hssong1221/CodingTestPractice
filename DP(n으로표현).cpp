#include <string>
#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int solution(int N, int number) {
    int answer = -1;

    unordered_set<int> set[8]; // 정렬x 중복x 

    int temp = 0;
    for (int i = 0; i < 8; i++) {
        temp = temp * 10 + N;       // N, NN, NNN ... NNNNNNNN까지
        set[i].insert(temp);
    }

    //ex) set[1]일땐 set[0] (+-*/) set[1], set[1] (+-*/) set[0] 
    //ex) set[2]일땐 set[0] (+-*/) set[2], set[1] (+-*/) set[1], set[2] (+-*/) set[0] 
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
    
    //set[i]안에 number가 있는지 앞에서부터 확인해서 최솟값찾기
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