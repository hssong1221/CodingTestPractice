#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> p) {

    int size = p.size();
    vector<int> answer(size, 0);
    vector<int> list = p;

    for (int i = 0; i < size; i++) {
        auto min_idx = min_element(list.begin() + i, list.end()) - list.begin();

        if (list[i] == list[min_idx])
            continue;

        int temp = 0;
        temp = list[i];
        list[i] = list[min_idx];
        list[min_idx] = temp;

        answer[i]++;
        answer[min_idx]++;
    }
    return answer;
}

int main() {
    solution({ 2,5,3,1,4 });
    return 0;
}

#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> periods, vector<vector<int>> payments, vector<int> estimates) {
    vector<int> answer(2, 0);

    for (int i = 0; i < periods.size(); i++) {
        //23개월 미만 제외
        if (periods[i] < 23)
            continue;

        // 이번달 금액
        int now = 0;
        for (int k = 0; k < payments[i].size(); k++)
            now += payments[i][k];

        // 다음달 금액 포함
        int next = 0;
        next = estimates[i] + now - payments[i][0];

        cout << periods[i] << " " << now << " " << next << endl;

        if (periods[i] == 23) { // 23개월
            // 다음달 vip
            if (900000 <= next)
                answer[0]++;
        }
        else if (24 <= periods[i] && periods[i] < 59) {     //24개월 부터 59개월 미만
            // vip x -> o
            if (now < 900000 && 900000 <= next)
                answer[0]++;
            // vip o -> x
            if (90000 <= now && next < 900000)
                answer[1]++;
        }
        else if (periods[i] == 59) {    //59개월
            cout << periods[i] << endl;
            // vip x -> 0
            if (now < 900000 && 600000 <= next)
                answer[0]++;
            // vip 0 - > x
            if (90000 <= now && next < 600000)
                answer[1]++;
        }
        else {  //60개월 ~
            if (600000 <= now && next < 600000)
                answer[1]++;
        }

        for (auto a : answer)
            cout << a << " ";
        cout << endl;
    }

    return answer;
}

int main() {
    solution({ 24, 59, 59, 60 }, { {50000, 50000, 50000, 50000, 50000, 50000, 50000, 50000, 50000, 50000, 50000, 50000},
        {50000, 50000, 50000, 50000, 50000, 50000, 50000, 50000, 50000, 50000, 50000, 50000},
        {350000, 50000, 50000, 50000, 50000, 50000, 50000, 50000, 50000, 50000, 50000, 50000} ,
        { 50000, 50000, 50000, 50000, 50000, 50000, 50000, 50000, 50000, 50000, 50000, 50000 } }, { 350000, 50000, 40000, 50000 });
    return 0;
}

#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

vector<string> split(string input, char delimeter) {
    vector<string> result;
    stringstream ss(input);
    string temp;
    while (getline(ss, temp, delimeter))
        result.push_back(temp);

    return result;
}

vector<int> solution(int n, vector<string> plans, vector<string> clients) {
    int cn = clients.size();
    vector<int> answer(cn, 0);


    vector<string> c;
    vector<string> p;
    vector<string> plist;

    for (int i = 0; i < clients.size(); i++) {
        c = split(clients[i], ' ');

        for (int k = 0; k < plans.size(); k++) {
            p = split(plans[k], ' ');

            for (auto a : p)
                cout << a << " ";
            cout << endl;


            for (int n = 1; n < p.size(); n++)
                plist.push_back(p[n]);

            string pp = "";
            for (int n = 0; n < plist.size(); n++)
                pp += plist[n];

            cout << c[0] << p[0] << endl;
            // 데이터사용량 확인
            if (stoi(p[0]) < stoi(c[0]))
                continue;

            cout << pp << endl;

            for (int n = 1; n < c.size(); n++) {
                if (pp.find(c[n]) == string::npos) {
                    cout << "noo" << endl;
                    answer[i] = 0;
                    break;
                }
                else if (pp.find(c[n]) >= 0) {
                    cout << "yes" << endl;
                    answer[i] = k + 1;
                }
            }
            if (answer[i] > 0)
                break;
        }
        cout << endl;
        plist.clear();
    }

    for (auto a : answer)
        cout << a << " ";

    return answer;
}

int main() {
    solution(5, { "100 1 3", "500 4", "2000 5" }, { "300 3 5", "1500 1", "100 1 3", "50 1 2" });
    return 0;
}

#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<vector<int>> visit(51, vector<int>(51, 0));

vector<char> list;

void DFS(int x, int y, vector<string> grid, vector<char> list) {
    if (grid[x][y] == '#') {
        list.pop_back();
        return;
    }
    if (x == grid.size() - 1 && y == grid.size() - 1) {
        cout << x << y;
    }

    visit[x][y] = 1;
    cout << x << " " << y << endl;
    list.push_back(grid[x][y]);

    //상
    if (x > 0) {
        if (visit[x - 1][y] == 0) {
            //cout << "상" << endl;
            DFS(x - 1, y, grid, list);
        }
    }
    //하
    if (x < grid.size() - 1) {
        if (visit[x + 1][y] == 0) {
            //cout << "하" << endl;
            DFS(x + 1, y, grid, list);
        }
    }
    //좌
    if (y > 0) {
        if (visit[x][y - 1] == 0) {
            //cout << "좌" << endl;
            DFS(x, y - 1, grid, list);
        }
    }
    //우
    if (y < grid[0].size() - 1) {
        if (visit[x][y + 1] == 0) {
            //cout << "우" << endl;
            DFS(x, y + 1, grid, list);
        }
    }
}

int solution(vector<string> grid, int k) {
    int answer = -1;
    DFS(0, 0, grid, list);

    return answer;
}

int main() {
    solution({ "..FF", "###F", "###." }, 4);
    return 0;
}