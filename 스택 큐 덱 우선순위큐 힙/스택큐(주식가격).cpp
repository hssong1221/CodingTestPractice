#include <string>
#include <vector>
#include <iostream>

using namespace std;

/// <summary>
/// 문제의 뜻이 뭐냐 하면
/// 가격은 1초마다 갱신됨
/// 현재 시점의 가격이 있는데 나중에 시간이 흘러서 만약 지금 값보다 떨어졌다면 그게 몇초가 흐르고 난 후 인지를 담아서 제출
/// 가격이 끝까지 안떨어지는 경우도 물론 있다.
/// </summary>

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    int time = 0;
    
    // 현재 시점에서 출발해서 마지막 시점까지 비교
    for (int i = 0; i < prices.size(); i++) {
        time = 0;
        for (int k = i + 1; k < prices.size(); k++) {
            if (prices[i] <= prices[k])
                time++;
            else {  // 기준 가격 아래로 내려감
                time++;
                break;
            }
        }
        // 몇초 지났는지 추가
        answer.push_back(time);

    }

    for (auto a : answer)
        cout << a;
    return answer;
}

int main() {
    //solution({ 1, 2, 3, 2, 3, 1 });
    solution({ 1, 2, 3, 2, 3 });
    return 0;
}