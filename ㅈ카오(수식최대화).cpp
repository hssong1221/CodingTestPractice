#include <string>
#include <vector>
#include <deque>
#include <iostream>
#include <limits.h>
#include <algorithm>

using namespace std;

long long SixCalc(deque<long long> n, deque<char> op);

long long solution(string expression) {
    long long answer = 0;
    deque<long long> num;
    deque<char> oper;
    string temp = "";
    int last = 0;

    // 숫자와 연산자를 따로 분리
    for (int i = 0; i < expression.length(); i++) {
        if (expression[i] == '*' || expression[i] == '+' || expression[i] == '-') {
            num.push_back(stoll(temp));
            oper.push_back(expression[i]);
            temp = "";
        }
        else
            temp += expression[i];
    }
    num.push_back(stoll(temp));

    /*for (auto n : num)
        cout << n << " ";
    cout << endl;
    for (auto o : oper)
        cout << o;*/

    answer = SixCalc(num, oper);
    return answer;
}

long long SixCalc(deque<long long> n, deque<char> op) {
    long long max = 0;
    long long temp = 0;

    deque<long long> tn = n;    //숫자
    deque<char> top = op;       //연산자

    vector<string> list = { "*+-", "*-+","+-*","+*-", "-+*", "-*+" };

    for (int i = 0; i < 6; i++) {
        tn = n;
        top = op;
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < top.size(); ) {
                cout << i << " " << top[k] << " " << list[i][j] << endl;

                for (auto n : tn)
                    cout << n << " ";
                cout << endl;
                for (auto o : top)
                    cout << o;
                cout << endl;

                if (top[k] == list[i][j]) {
                    if (top[k] == '+') {
                        temp = tn[k] + tn[k + 1];
                    }
                    else if (top[k] == '-') {
                        temp = tn[k] - tn[k + 1];
                    }
                    else if (top[k] == '*') {
                        temp = tn[k] * tn[k + 1];
                    }

                    tn.erase(tn.begin() + k);
                    tn.erase(tn.begin() + k);
                    tn.insert(tn.begin() + k, temp);

                    top.erase(top.begin() + k);


                    for (auto n : tn)
                        cout << n << " ";
                    cout << endl;
                    for (auto o : top)
                        cout << o;
                    cout << endl;

                }
                else
                    k++;

                cout << "----------------------------" << endl;

            }
        }
        max = std::max(max, abs(tn[0]));
        cout << "현재 최대값 : " << max << endl;
    }

    cout << max;
    return max;
}


int main() {

    solution("100-200*300-500+20");

    return 0;
}