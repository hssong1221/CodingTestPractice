#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 0;
    vector<vector<int>> r;
    r = routes;

    sort(r.begin(), r.end(), greater<>());

    int temp = 300001;
    for (int i = 0; i < r.size(); i++) {
        cout << r[i][1] << " " << r[i][0] << endl;
        if (temp > r[i][1]) {
            temp = r[i][0];
            answer++;
        }
    }
    cout << answer;
    return answer;
}

int main() {
    solution({ {-20,15},{-14,-5},{-18,-13},{-5,-3} });
    return 0;
}