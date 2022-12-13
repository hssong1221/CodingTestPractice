#include <string>
#include <vector>
#include <string>
#include <map>
#include <iostream>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;

    map<string, bool> m;
    for (int i = 0; i < phone_book.size(); i++)
        m[phone_book[i]] = true;

    for (int i = 0; i < phone_book.size(); i++) {
        for (int k = 0; k < phone_book[i].size() - 1; k++) {
            // ��ȣ�� ��� ��ȣ�� ���ϴ°� �����ɸ�
            // �ش� ��ȣ�� �տ��� ���� �߶� �ϳ��� �ֳ����� Ȯ���ϸ� �� ����
            string temp = phone_book[i].substr(0, k + 1);
            if (m[temp])
                return false;
        }
    }

    return answer;
}

int main() {
    solution({ "119", "97674223", "1195524421" });
    return 0;
}

/* 20221212 �籸��
bool solution(vector<string> phone_book) {
    bool answer = true;

    map<string, bool> m;
    for (auto p : phone_book)
        m[p] = true;

    for (int i = 0; i < phone_book.size(); i++) {
        for (int j = 0; j < phone_book[i].size() - 1; j++) {
            // ��ü ��x, �տ��� ���� �߶� �ʿ� �ֳ� ���� Ȯ���� ����
            string temp = phone_book[i].substr(0, j + 1);
            if (m[temp]) // �߰� ��� false
                return false;
        }
    }
    return answer;
}*/