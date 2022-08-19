#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


//303 > 330 false�� �ڸ� �ٲ�
bool sorting(string a, string b) {
    return a + b > b + a;
}
string solution(vector<int> numbers) {
    string answer = "";
    vector<string> temp;
    string result;

    //���� ��ġ���� ���ڷ� �ٲ����
    for (int i = 0; i < numbers.size(); i++) {
        temp.push_back(to_string(numbers[i]));
    }
    //�������� �ϸ� 30�� 3���� ������ �ͼ� custom����
    sort(temp.begin(), temp.end(), sorting);
    
    //������ 0 �Ǵ� ���� ������  0���� �� 0�� 
    if (temp[0] == "0")
        return "0";

    //���� ū �� �� �ٿ��� ����
    for (int i = 0; i < temp.size(); i++) {
        answer += temp[i];
    }
    return answer;
}

int main() {

    solution({ 3,30,34,5,9 });

    return 0;
}