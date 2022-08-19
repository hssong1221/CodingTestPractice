#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int> total;
    map<string, map<int, int>> list;

    //�帣�� ��ü �����, ��� �ε����� ��� ��
    for (int i = 0; i < genres.size(); i++) {
        total[genres[i]] += plays[i];
        list[genres[i]][i] = plays[i];
    }
    int max = 0;
    string name = "";
    int num = 0;

    while (total.size() > 0) {
        max = 0;
        name = "";
        // ���� ���� ������� ���� �帣 �̱�
        for (auto &to : total) {
            if (to.second > max)
                name = to.first;
        }

        // �տ��� 2� �̱�
        for (int i = 0; i < 2; i++) {
            max = 0;
            num = 0;
            for (auto &li : list[name]) {
                if (li.second > max) {
                    num = li.first;
                    max = li.second;
                }
            }
            // �̴ٰ� ������ ����
            if (max == 0) {
                break;
            }
            // �信 �ְ� ���� �� �����
            answer.push_back(num);
            list[name].erase(num);
        }
        // ���� �帣 �����
        total.erase(name);
    }
    for (auto a : answer) {
        cout << a << " ";
    }
    return answer;
}

int main() {
    solution({ "classic", "pop", "classic", "classic", "pop" }, { 500, 600, 150, 800, 2500 });
    return 0;
}