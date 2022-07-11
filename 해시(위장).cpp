#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;

    map <string, int> num;

    // �� ���� ������ �߿����� �� �̸��� �ʿ����
    for (int i = 0; i < clothes.size(); i++) {
        if (num[clothes[i][1]] == 0) {
            num[clothes[i][1]] = 1;
        }
        else {
            num[clothes[i][1]] += 1;
        }
    }

    // ��� ����� �� - ���� �� ���Դ� ��� + 1 ���� 
    for (auto &n : num) {
        answer *= n.second + 1;
    }

    // �� ���� �ִ� ��� ����
    answer--;

    cout << answer;
    return answer;
}

int main() {
    solution({ {"yellow_hat", "headgear"},{"blue_sunglasses", "eyewear"},{"green_turban", "headgear"} });
    return 0;
}