#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    vector<int> temp;
    int t;
    for (int i = 0; i < progresses.size(); i++) {
        t = (99 - progresses[i]);
        if (t % speeds[0] > 0) {
            temp.push_back((t / speeds[i]) + 1);
        }
        else
            temp.push_back(t / speeds[i]);
    }
    int ans;
    int sub;
    for (int i = 0; i < temp.size(); i++) {
        ans = 0;
        sub = temp[i];

        for (int k = i; k < temp.size(); k++) {
            if (sub <= 0) 
                break;
            
            temp[k] -= sub;
        }
        for (int j = i; j < temp.size(); j++) {
            if (temp[j] <= 0) 
                ans++;
            else 
                break;
        }
        i += ans - 1;
        //cout << ans << endl;
        answer.push_back(ans);
    }  
    for (auto a : answer)
        cout << a;
    return answer;
}

int main() {
    solution({ 93, 30, 55, 60, 40, 65 }, { 1, 30, 5 , 10, 60, 7 });
    return 0;
}