#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;

    // �ʱⰪ
    answer.push_back(arr[0]);

    for (int i = 1; i < arr.size(); i++) {
        // �� ���߿� ���� �Ͱ� ��
        if (answer.back() == arr[i])
            continue;
        else
            answer.push_back(arr[i]);
    }
    
    for (auto a : answer)
        cout << a << " ";

    return answer;
}
int main() {
    solution({ 1,1,3,3,0,1,1 });
    return 0;
}