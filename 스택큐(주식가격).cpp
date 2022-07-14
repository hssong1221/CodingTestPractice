#include <string>
#include <vector>
#include <iostream>

using namespace std;

/// <summary>
/// ������ ���� ���� �ϸ�
/// ������ 1�ʸ��� ���ŵ�
/// ���� ������ ������ �ִµ� ���߿� �ð��� �귯�� ���� ���� ������ �������ٸ� �װ� ���ʰ� �帣�� �� �� ������ ��Ƽ� ����
/// ������ ������ �ȶ������� ��쵵 ���� �ִ�.
/// </summary>

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    int time = 0;
    
    // ���� �������� ����ؼ� ������ �������� ��
    for (int i = 0; i < prices.size(); i++) {
        time = 0;
        for (int k = i + 1; k < prices.size(); k++) {
            if (prices[i] <= prices[k])
                time++;
            else {  // ���� ���� �Ʒ��� ������
                time++;
                break;
            }
        }
        // ���� �������� �߰�
        answer.push_back(time);

    }

    for (auto a : answer)
        cout << a;
    return answer;
}

int main() {
    //solution({ 1, 2, 3, 2, 3, 1 });
    solution({ 1, 2, 3, 2, 3 });
    return 0;
}