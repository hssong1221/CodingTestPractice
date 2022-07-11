#include <iostream>

using namespace std;

long long solution(int w, int h) {
    long long answer = 1;

    long long a = w;
    long long b = h;

    long long box = a * b;
    long long temp = 0;
    
    //유클리드 호제법
    while (b != 0) {
        temp = a % b;
        a = b;
        b = temp;
    }

    temp = (long long)w + h - a;
    answer = box - temp;
    return answer;
}

int main(){
    solution(8, 12);
    return 0;
}