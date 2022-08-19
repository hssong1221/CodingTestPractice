#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int> total;
    map<string, map<int, int>> list;

    //장르당 전체 재생수, 곡당 인덱스랑 재생 수
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
        // 현재 가장 재생수가 많은 장르 뽑기
        for (auto &to : total) {
            if (to.second > max)
                name = to.first;
        }

        // 앞에서 2곡만 뽑기
        for (int i = 0; i < 2; i++) {
            max = 0;
            num = 0;
            for (auto &li : list[name]) {
                if (li.second > max) {
                    num = li.first;
                    max = li.second;
                }
            }
            // 뽑다가 없으면 말기
            if (max == 0) {
                break;
            }
            // 답에 넣고 넣은 곡 지우기
            answer.push_back(num);
            list[name].erase(num);
        }
        // 넣은 장르 지우기
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