#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

bool Prime(int n) { // (소수인지 알고 싶은 숫자)
    if (n < 2)
        return false;

    // 자신의 제곱근 아래 숫자로 안나눠 떨어지면 소수임
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }

    return true;
}

int solution(string numbers) {
    int answer = 0;
    vector<int> num;                            //받은 숫자 

    vector<int> permutation;

    // 문자를 숫자로
    int temp = stoi(numbers);               

    // 숫자를 한글자 한글자 분해
    for (int i = 0; i < numbers.length(); i++) {
        num.push_back(temp % 10);
        temp /= 10;
    }
    sort(num.begin(), num.end());

    // 모든 경우의 수 (순열)
    do {
        for (int k = num.size(); 0 < k; k--) {
            string result = "";
            for (int i = 0; i < num.size() - k + 1; i++) {
                result += to_string(num[i]);
            }
            permutation.push_back(stoi(result));
        }

    } while (next_permutation(num.begin(), num.end()));

    // 정렬해서 똑같은 숫자 제외
    sort(permutation.begin(), permutation.end());
    permutation.erase(unique(permutation.begin(), permutation.end()), permutation.end());

    // 소수인지 아닌지 판별
    for (int i = 0; i < permutation.size(); i++) {
        if (Prime(permutation[i]))
            answer++;
    }

    cout << answer;
    return answer;
}

int main() {
    solution("17");
    return 0;
}
