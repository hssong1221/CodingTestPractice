#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int rh = 0; // 오른손 위치
    int lh = 0; // 왼손 위치
    
    vector<pair<int, int>> keypad;

    keypad.push_back(make_pair(3, 1));  // 0의 위치
    for (int i = 0; i < 4; i++) {       // 숫자들의 위치
        for (int j = 0; j < 3; j++)
            keypad.push_back(make_pair(i, j));
    }

    for (int i = 0; i < numbers.size(); i++) {
        if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7) {
            answer += 'L';
            lh = numbers[i];
        }
        else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9) {
            answer += 'R';
            rh = numbers[i];
        }
        else { // 2580
            int rd = 0; //오른손 거리
            int ld = 0; // 왼손 거리
            
            rd = abs(keypad[rh].first - keypad[numbers[i]].first) + abs(keypad[rh].second - keypad[numbers[i]].second);
            ld = abs(keypad[lh].first - keypad[numbers[i]].first) + abs(keypad[lh].second - keypad[numbers[i]].second);
            cout << rd << " " << ld << endl;
            if (rd == ld) {
                if (hand == "right") {
                    answer += 'R';
                    rh = numbers[i];
                }
                else {
                    answer += 'L';
                    lh = numbers[i];
                }
            }
            else if (rd < ld) {
                answer += 'R';
                rh = numbers[i];
            }
            else {
                answer += 'L';
                lh = numbers[i];
            }
        }
        cout << "answer : " << answer << endl;
    }
    cout << answer;
    return answer;
}

int main() {
    solution({ 1,3,4,5,8,2,1,4,5,9,5 }, "right");
    return 0;
}