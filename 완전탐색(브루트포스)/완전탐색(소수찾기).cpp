#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

bool Prime(int n) { // (�Ҽ����� �˰� ���� ����)
    if (n < 2)
        return false;

    // �ڽ��� ������ �Ʒ� ���ڷ� �ȳ��� �������� �Ҽ���
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }

    return true;
}

int solution(string numbers) {
    int answer = 0;
    vector<int> num;                            //���� ���� 

    vector<int> permutation;

    // ���ڸ� ���ڷ�
    int temp = stoi(numbers);               

    // ���ڸ� �ѱ��� �ѱ��� ����
    for (int i = 0; i < numbers.length(); i++) {
        num.push_back(temp % 10);
        temp /= 10;
    }
    sort(num.begin(), num.end());

    // ��� ����� �� (����)
    do {
        for (int k = num.size(); 0 < k; k--) {
            string result = "";
            for (int i = 0; i < num.size() - k + 1; i++) {
                result += to_string(num[i]);
            }
            permutation.push_back(stoi(result));
        }

    } while (next_permutation(num.begin(), num.end()));

    // �����ؼ� �Ȱ��� ���� ����
    sort(permutation.begin(), permutation.end());
    permutation.erase(unique(permutation.begin(), permutation.end()), permutation.end());

    // �Ҽ����� �ƴ��� �Ǻ�
    for (int i = 0; i < permutation.size(); i++) {
        if (Prime(permutation[i]))
            answer++;
    }

    cout << answer;
    return answer;
}

int main() {
    solution("17");
    return 0;
}
