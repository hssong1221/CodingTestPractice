#include <string>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    string last = "";
    string now = "";
    int flag = 0;
    int min = 1001;

    for (int i = 1; i <= s.length(); i++) {
        flag = 1;
        answer = s.length();
        for (int k = 0; k <= s.length() / i; k++) {
            now = s.substr(k * i, i);

            cout << last << " " << now << " " << endl;
            if (last == now) {
                flag++;
                answer -= i;
            }
            else if (last != now) {
                if (1 < flag && flag < 10)
                    answer += 1;
                if (10 <= flag && flag < 100)
                    answer += 2;
                if (100 <= flag && flag < 100)
                    answer += 3; 
                if (1000 == flag)
                    answer += 4;

                flag = 1;
            }

            cout << "answer" << answer << endl;
            last = now;
        }
        if (1 < flag && flag < 10)
            answer += 1;
        if (10 <= flag && flag < 100)
            answer += 2;
        if (100 <= flag && flag < 100)
            answer += 3;
        if (1000 == flag)
            answer += 4;

        if (answer < min)
            min = answer;
    }
    answer = min;
    cout << answer;
    return answer;
}

int main() {
    solution("aabbaccc");
    return 0;
}