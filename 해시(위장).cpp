#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;

    map <string, int> num;

    // 옷 종류 갯수만 중요하지 옷 이름은 필요없음
    for (int i = 0; i < clothes.size(); i++) {
        if (num[clothes[i][1]] == 0) {
            num[clothes[i][1]] = 1;
        }
        else {
            num[clothes[i][1]] += 1;
        }
    }

    // 모든 경우의 수 - 구할 때 안입는 경우 + 1 적용 
    for (auto &n : num) {
        answer *= n.second + 1;
    }

    // 다 벗고 있는 경우 제외
    answer--;

    cout << answer;
    return answer;
}

int main() {
    solution({ {"yellow_hat", "headgear"},{"blue_sunglasses", "eyewear"},{"green_turban", "headgear"} });
    return 0;
}