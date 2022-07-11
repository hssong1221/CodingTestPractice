#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iostream>

using namespace std;

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

    unordered_map<string, int> map;
    vector<char> c_list;
    

    for (int j = 0; j < course.size(); j++) {
        int r = course[j];      // 조합할 갯수

        for (int i = 0; i < orders.size(); i++) {
            if (orders[i].length() < r) // 조합 할 갯수보다 멤버가 적을때
                continue;

            for (int k = 0; k < orders[i].length(); k++)    // 문자열을 쪼개서 문자로 넣음
                c_list.push_back(orders[i][k]);

            sort(c_list.begin(), c_list.end());     // 조합 구하기 위해 정렬

            vector<bool> ox(c_list.size(), false);          
            for (int k = 0; k < r; k++)
                ox[k] = true;

            string s;
            do {            // 조합 구해서 맵에 넣음
                s = "";
                for (int n = 0; n < c_list.size(); ++n) {
                    if (ox[n]) {
                        s += c_list[n];
                    }
                }
                if (map[s] == 0) // 최초
                    map[s] = 1;
                else             // 중복
                    map[s] += 1;    
            } while (prev_permutation(ox.begin(), ox.end()));

            c_list.clear();
            ox.clear();
        }

        int max = 0;
        for (auto it = map.begin(); it != map.end(); it++) {    // 최대 value 구하기
            if (it->second > max)
                max = it->second;
        }

        for (auto it = map.begin(); it != map.end(); it++) {    // vaule 여러개 있는 경우
            if (max == it->second && max != 1)
                answer.push_back(it->first);
        }

        map.clear();
    }

    sort(answer.begin(), answer.end()); // 정렬
    for (auto a : answer)
        cout << a <<" ";
    
    return answer;
}

int main() {
    solution({ "XYZ", "XWY", "WXA" }, {2,3,4});
    return 0;
}