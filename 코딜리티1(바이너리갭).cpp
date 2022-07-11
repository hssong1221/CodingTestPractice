#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int N) {
    int R = 0;
    vector<int> v;

    while (N != 1) {
        R = N % 2;
        N /= 2;
        if (R == 1)
            v.push_back(1);
        else
            v.push_back(0);

    }
    v.push_back(1);

    for (auto i : v)
        cout << i << " ";
    cout << endl;

    bool flag = false;
    vector<int> ans(1, 0);
    int zero = 0;

    for (auto i : v) {
        if (i == 1 && flag == false) {
            cout << "1 ";
            zero = 0;
            flag = true;
        }
        else if (i == 1 && flag == true) {
            cout << "1 ";
            ans.push_back(zero);
            zero = 0;
        }
        else {
            cout << "0 ";
            zero++;
        }
    }
    int max = *max_element(ans.begin(), ans.end());
    cout << endl << max;
    return max;
}

int main() {
    solution(32);
    return 0;
}
