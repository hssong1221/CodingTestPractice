#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// H-Index�� ���� �̾߱��� ���ظ� ���� �ؾ��Ѵ�
int solution(vector<int> citations) {
    int answer = 0;

    vector<int> temp;
    temp = citations;

    int size = temp.size();
    //�������� ����
    sort(temp.begin(), temp.end(), greater<>());
    // �ο�� Ƚ���� ������ ������ ������
    for (int i = 0; i < temp.size(); i++) {
        if (i < temp[i])
            answer++;
    }

    cout << answer;
    return answer;
}

int main() {
    solution({ 3,0,6,1,5 });
    return 0;
}