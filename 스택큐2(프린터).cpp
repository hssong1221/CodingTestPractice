#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    vector<int> p;
    p = priorities;
    int lo;
    lo = location;

    int temp;
    int max = 0;
    while (true) {
        max = *max_element(p.begin(), p.end());
        temp = 0;
        if (p[0] < max) {
            temp = p.front();
            p.erase(p.begin());
            p.push_back(temp);
            if (lo == 0)
                lo += p.size() - 1;
            else
                lo--;

            cout << lo << endl;
        }
        else if (p[0] == max) {
            p.erase(p.begin());
            answer++;
            if (lo == 0)
                break;
            else
                lo--;
            cout << lo << endl;
        }
    }
    return answer;
}

int main() {
    solution({ 1,1,9,1,1,1 }, 0);

    return 0;
}