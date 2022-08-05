#include <string>
#include <vector>
#include <deque>
#include <sstream>
#include <algorithm>
#include <iostream>

using namespace std;

// 문자열 자르기
vector<string> split(string input, char delimeter) {
    vector<string> result;
    stringstream ss(input);
    string temp;
    while (getline(ss, temp, delimeter))
        result.push_back(temp);

    return result;
}

int main() {
    //총 테스트 횟수입력
    int tcase;
    cin >> tcase;

    // 테스트당 몇번 씩 할껀지
    for (int i = 0; i < tcase; i++) {
        int line;
        cin >> line;
        cin.ignore(); // 앞에서 쓴 엔터포함되기 때문에 입력 버퍼 비우기

        deque<int> d; // 앞뒤로 제거하기 때문에 덱을 사용해 보았다. 
        vector<string> result;
        for (int k = 0; k < line; k++) {
            string s;
            getline(cin, s); // 띄어쓰기 포함 문자열 

            result = split(s, ' '); // 문자열자르기

            if (result[0] == "I") {
                d.push_back(stoi(result[1]));
                // 덱은 자동정렬이 안되기때문에 직접해준다. 
                sort(d.begin(), d.end());
            }
            else if (result[0] == "D") {
                if (d.empty())
                    continue;

                if (result[1] == "-1")
                    d.pop_front();
                else if (result[1] == "1")
                    d.pop_back();
            }
            result.clear();
        }

        if (!d.empty())
            cout << d.back() << " " << d.front() << "\n";
        else
            cout << "EMPTY" << "\n";
    }
    return 0;
}

//덱으로는 안풀림