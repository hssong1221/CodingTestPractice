#include <string>
#include <vector>
#include <deque>
#include <sstream>
#include <algorithm>
#include <iostream>

using namespace std;

// ���ڿ� �ڸ���
vector<string> split(string input, char delimeter) {
    vector<string> result;
    stringstream ss(input);
    string temp;
    while (getline(ss, temp, delimeter))
        result.push_back(temp);

    return result;
}

int main() {
    //�� �׽�Ʈ Ƚ���Է�
    int tcase;
    cin >> tcase;

    // �׽�Ʈ�� ��� �� �Ҳ���
    for (int i = 0; i < tcase; i++) {
        int line;
        cin >> line;
        cin.ignore(); // �տ��� �� �������ԵǱ� ������ �Է� ���� ����

        deque<int> d; // �յڷ� �����ϱ� ������ ���� ����� ���Ҵ�. 
        vector<string> result;
        for (int k = 0; k < line; k++) {
            string s;
            getline(cin, s); // ���� ���� ���ڿ� 

            result = split(s, ' '); // ���ڿ��ڸ���

            if (result[0] == "I") {
                d.push_back(stoi(result[1]));
                // ���� �ڵ������� �ȵǱ⶧���� �������ش�. 
                sort(d.begin(), d.end());
            }
            else if (result[0] == "D") {
                if (d.empty())
                    continue;

                if (result[1] == "-1")
                    d.pop_front();
                else if (result[1] == "1")
                    d.pop_back();
            }
            result.clear();
        }

        if (!d.empty())
            cout << d.back() << " " << d.front() << "\n";
        else
            cout << "EMPTY" << "\n";
    }
    return 0;
}

//�����δ� ��Ǯ��