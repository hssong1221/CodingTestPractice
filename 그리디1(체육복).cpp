#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n;

    vector<int> cloth(n , 1);
    for (int i = 0; i < lost.size(); i++) {
        cloth[lost[i] - 1] -= 1;
    }
    for (int i = 0; i < reserve.size(); i++) {
        cloth[reserve[i] - 1] += 1;
    }

    int s = cloth.size();
    // 첫번째
    if (cloth[0] == 2 && cloth[1] == 0) {
        cloth[1]++;
        cloth[0]--;
    }
    // 사이
    for (int i = 1; i < s - 1; i++) {
        if (cloth[i] == 2) {
            if (cloth[i - 1] == 0) {
                cloth[i]--;
                cloth[i - 1]++;
            }
            else if (cloth[i + 1] == 0) {
                cloth[i]--;
                cloth[i + 1]++;
            }
        }
    }
    // 마지막
    if (cloth[s - 1] == 2 && cloth[s - 2] == 0) {
        cloth[s - 2]++;
        cloth[s - 1]--;
    }
    
    for (auto c : cloth) {
        if (c == 0)
            answer--;
    }
    cout << answer;
    return answer;
}
int main() {
    solution(5, { 2,4 }, { 1,3,5 });
    return 0;
}