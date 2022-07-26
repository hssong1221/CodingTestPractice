#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// H-Index의 대한 이야기의 이해를 먼저 해야한다
int solution(vector<int> citations) {
    int answer = 0;

    vector<int> temp;
    temp = citations;

    int size = temp.size();
    //내림차순 정렬
    sort(temp.begin(), temp.end(), greater<>());
    // 인용된 횟수가 개수랑 같아질 때까지
    for (int i = 0; i < temp.size(); i++) {
        if (i < temp[i])
            answer++;
    }

    cout << answer;
    return answer;
}

int main() {
    solution({ 3,0,6,1,5 });
    return 0;
}