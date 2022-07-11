#include <string>
#include <vector>
#include <algorithm>
#include <iostream>


using namespace std;

int solution(string name) {
    int answer = 0;
    int size = name.length();
    char* list = new char[size + 1];
    //string�� char�迭��
    strcpy(list, name.c_str());
    
    //�¿� �̵� �ִ밪
    int vec = size - 1;
    for (int i = 0; i < size; i++) {
        //���Ʒ� ������ Ƚ��(���ĺ�)
        if (list[i] - 'A' > 13) {
            answer += 13 - (list[i] - 'N');
        }
        else {
            answer += list[i] - 'A';
        }

        //���� ��ġ �������� ���ӵǴ� A�� ���� (���ӵ� A�� ������ ��ġ)
        int k = i + 1;
        while (true) {
            if (list[k] == 'A')
                k++;
            else
                break;
        }
        // �¿��̵�
        // ������ ���� �ڷ� ���� ��� ����
        // ���� ���� ��� ���°�, �ڷ� �ٽ� ���� �պ��̶� 2�迡 ��ü���̿��� A �� ����ؼ� ���� 
        vec = min(vec, i * 2 + size - k);
        // ó������ �ڷ� ����A�ڱ��� ���ٰ� �ٽ� ������ ���°� �������(�̰� ���� ������..)
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