#include <string>
#include <vector>
#include <iostream>
#include <climits>
#include <map>
#include <sstream>
#include <set>
#include <algorithm>
#include <bitset>
#include <deque>
#include <unordered_map>
#include <queue>

using namespace std;

vector<vector<int>> v1(32, vector<int>(32, 0)); // 1024ĭ
vector<vector<int>> v2(32, vector<int>(32, 0)); // 1024ĭ
string s1;
string s2;

void DFS1(int x, int y, int n , string s, int idx) {
    if (s[idx] == 'p' ) {
        int num = n / 2;
        if(idx + 4  < s.size()){
            if (s[idx + 1] != 'p' && s[idx + 2] != 'p' && s[idx + 3] != 'p' && s[idx + 4] != 'p') {
                DFS1(x, y, num, s, idx + 1);
                DFS1(x + num, y, num, s, idx + 2);
                DFS1(x + num, y + num, num, s, idx + 3);
                DFS1(x, y + num, num, s, idx + 4);
            }
        }
        else {
            DFS1(x, y, num, s, idx + 1);
            DFS1(x + num, y, num, s, idx + 1);
            DFS1(x + num, y + num, num, s, idx + 1);
            DFS1(x, y + num, num, s, idx + 1);
        }

    }

    cout << s[idx] << endl;;
    for (int i = x; i < x + n; i++) {
        for (int j = y; j < y + n; j++) {
            if (s[idx] == 'w') {
                v1[i][j] = 0;
            }
            else {
                v1[i][j] = 1;
            }
        }
    }
}

int solution(string S1, string S2) {
    int answer = 0;
    s1 = S1;
    s2 = S2;
    s1 += "0";
    s2 += "0";
    int n = 32;
    DFS1(0, 0, n, s1, 0);

    for (auto a : v1) {
        for (auto b : a)
            cout << b << " ";
        cout << endl;
    }

    cout << endl;


    return answer;
}

int main() {
    solution("ppwwwbpbbwwbw", "b");
    return 0;
}