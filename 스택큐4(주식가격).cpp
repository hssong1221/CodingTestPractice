#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    int temp = 0;
    for (int i = 0; i < prices.size(); i++) {
        temp = 0;
        for (int k = i + 1; k < prices.size(); k++) {
            if (prices[i] <= prices[k])
                temp++;
            else {
                temp++;
                break;
            }
        }
        answer.push_back(temp);

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