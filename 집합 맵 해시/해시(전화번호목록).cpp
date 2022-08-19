#include <string>
#include <vector>
#include <string>
#include <map>
#include <iostream>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;

    map<string, bool> m;
    for (int i = 0; i < phone_book.size(); i++)
        m[phone_book[i]] = true;

    for (int i = 0; i < phone_book.size(); i++) {
        for (int k = 0; k < phone_book[i].size() - 1; k++) {
            // 번호를 모든 번호랑 비교하는건 오래걸림
            // 해당 번호를 앞에서 부터 잘라서 하나씩 있나없나 확인하면 더 빠름
            string temp = phone_book[i].substr(0, k + 1);
            if (m[temp])
                return false;
        }
    }

    return answer;
}

int main() {
    solution({ "119", "97674223", "1195524421" });
    return 0;
}