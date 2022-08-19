#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <deque>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;

    deque<int> p;
    for (auto pe : people)
        p.push_back(pe);

    sort(p.begin(), p.end());
    
    // �� �ջ���� limit������ ��ΰ� ȥ�� Ÿ����
    if (p.front() > limit / 2) {
        answer = people.size();
        return answer;
    }
    while(true) {
        // ����� 1�� ������ �¿�� ��
        if (p.size() == 1) {
            answer++;
            break;
        }
        else if (p.size() == 0)
            break;

        //�ִ� �ο� 2���̴ϱ� ���� ���ſ�� ������� �¿�
        if (p[0] + p.back() <= limit) {
            p.pop_back();
            p.pop_front();
            answer++;
        }
        // ���ſ��� ��Ÿ�� ���ſ��� ȥ��Ž
        else {
            p.pop_back();
            answer++;
        }
    }
    cout << answer;

    return answer;
}

int main() {
    solution({ 70,50,  80,50 }, 100);
    return 0;
}