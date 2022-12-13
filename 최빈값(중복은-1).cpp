#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int solution(vector<int> array) {
    int answer = 0;
    map<int, int> m;

    for (auto a : array)
        m[a]++;

    int num = 0;
    int max = 0;

    for (auto iter = m.begin(); iter != m.end(); iter++) {
        if (iter->second > max) {
            num = iter->first;
            max = iter->second;
        }
    }
    int temp = 0;
    for (auto iter = m.begin(); iter != m.end(); iter++) {
        if (iter->second == max)
            temp++;
    }
    if (temp > 1)
        answer = -1;
    else
        answer = num;
    return answer;
}

int main() {
    solution({ 1,2,3,3,3,4 });
    return 0;
}