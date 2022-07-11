// 프로그래머스 레벨2 연습문제
#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer(arr1.size(), vector<int>(arr2[0].size(), 0));

    int temp;
    for (int i = 0; i < arr1.size(); i++) {
        for (int j = 0; j < arr2[0].size(); j++) {
            temp = 0;
            for (int k = 0; k < arr2.size(); k++) {
                temp += arr1[i][k] * arr2[k][j];
                //cout << i << " " << k << endl;
                //cout << k << " " << j << endl;
            }
            answer[i][j] = temp;
        }
    }
    for (auto a : answer) {
        for(auto b : a)
            cout << b;
        cout << endl;
    }
    return answer;
}

int main() {
    //solution({ {1,4},{3,2},{4,1} }, { {3,3},{3,3} });
    solution({ {2, 3, 2},{4, 2, 4},{3, 1, 4} }, { {5, 4},{2, 4},{3, 1} });
    return 0;
}