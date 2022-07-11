#include <string>
#include <vector>
#include <algorithm>
#include <iostream>


using namespace std;

int solution(string name) {
    int answer = 0;
    int size = name.length();
    char* list = new char[size + 1];
    //string을 char배열로
    strcpy(list, name.c_str());
    
    //좌우 이동 최대값
    int vec = size - 1;
    for (int i = 0; i < size; i++) {
        //위아래 누르는 횟수(알파벳)
        if (list[i] - 'A' > 13) {
            answer += 13 - (list[i] - 'N');
        }
        else {
            answer += list[i] - 'A';
        }

        //현재 위치 다음부터 연속되는 A의 개수 (연속된 A의 마지막 위치)
        int k = i + 1;
        while (true) {
            if (list[k] == 'A')
                k++;
            else
                break;
        }
        // 좌우이동
        // 앞으로 갈지 뒤로 갈지 계속 선택
        // 가던 방향 계속 가는것, 뒤로 다시 가면 왕복이라 2배에 전체길이에서 A 수 고려해서 빼기 
        vec = min(vec, i * 2 + size - k);
        // 처음부터 뒤로 연속A뒤까지 갔다가 다시 앞으로 가는게 빠른경우(이걸 어케 생각함..)
        vec = min(vec, (size - k) * 2 + i);
    }
    answer += vec;
    cout << answer;
    delete[] list;

    return answer;
}

int main() {
    solution("JAN");
    return 0;
}