#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


//303 > 330 false라 자리 바뀜
bool sorting(string a, string b) {
    return a + b > b + a;
}
string solution(vector<int> numbers) {
    string answer = "";
    vector<string> temp;
    string result;

    //숫자 합치려면 문자로 바꿔야함
    for (int i = 0; i < numbers.size(); i++) {
        temp.push_back(to_string(numbers[i]));
    }
    //문자정렬 하면 30이 3보다 앞으로 와서 custom정렬
    sort(temp.begin(), temp.end(), sorting);
    
    //문제에 0 또는 양의 정수라  0오면 걍 0임 
    if (temp[0] == "0")
        return "0";

    //가장 큰 수 쭉 붙여서 저장
    for (int i = 0; i < temp.size(); i++) {
        answer += temp[i];
    }
    return answer;
}

int main() {

    solution({ 3,30,34,5,9 });

    return 0;
}