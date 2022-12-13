#include <string>
#include <vector>
#include <map>
#include <algorithm>

#include <iostream>

using namespace std;

int solution(vector<int> array, int n) {
    int answer = 0;
    int temp = 999;
    sort(array.begin(), array.end());
    for (auto a : array) {
        if (temp >abs( n - a)) {
            temp = abs(n - a);
            answer = a;
        }
        
    }
    cout << answer << endl;
    return answer;
}

int main(void) {
    solution({ 3,10,28, 32 }, 20);
    return 0;
}