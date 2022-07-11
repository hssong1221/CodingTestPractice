#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;

    //rows X columns 행렬
    vector<vector<int>> xy(rows, vector <int>(columns, 0));
    for (int i = 0; i < xy.size(); i++) {
        for (int j = 0; j < xy[i].size(); j++) {
            xy[i][j] = j + 1 + (columns * i);
        }
    }

    deque<int> list;
    int x = 0;
    int y = 0;
    for (int i = 0; i < queries.size(); i++) {
    //for (int i = 0; i < 1; i++) {
        x = abs(queries[i][3] - queries[i][1]);
        y = abs(queries[i][2] - queries[i][0]);

        cout << queries[i][3] - queries[i][1] << endl;
        cout << queries[i][2] - queries[i][0] << endl;

        int temp = 0;
        //상
        for (int k = 0; k <= x; k++)
            list.push_back(xy[queries[i][0] - 1][queries[i][1] - 1 + k]);
        
        //우
        for (int k = 0; k < y; k++)
            list.push_back(xy[queries[i][0] + k][queries[i][3] - 1]);

        //하
        for (int k = 1; k <= x; k++)
            list.push_back(xy[queries[i][2] - 1][queries[i][3] - 1 - k]);

        //좌
        for (int k = 1; k < y; k++)
            list.push_back(xy[queries[i][2] - 1 - k][queries[i][1] - 1]);


        for (auto a : list)
            cout << a <<  " ";
        cout << endl;

        // 가장 작은 수 넣기
        temp = *min_element(list.begin(), list.end());
        answer.push_back(temp);

        // 하나씩 밀어서 넣기
        temp = list.back();
        list.push_front(temp);
        list.pop_back();

        //상
        int j = 0;
        for (int k = 0; k <= x; k++)
            xy[queries[i][0] - 1][queries[i][1] - 1 + k] = list[j++];

        //우
        for (int k = 0; k < y; k++)
            xy[queries[i][0] + k][queries[i][3] - 1] = list[j++];

        //하
        for (int k = 1; k <= x; k++)
            xy[queries[i][2] - 1][queries[i][3] - 1 - k] = list[j++];

        //좌
        for (int k = 1; k < y; k++) {
                xy[queries[i][2] - 1 - k][queries[i][1] - 1] = list[j++];
        }

        for (auto a : xy) {
            for(auto b : a)
                cout << b << '\t';
            cout << endl;
        }

        for(auto a : answer)
            cout << a << endl;

        list.clear();
    }

    return answer;
}

int main() {
    solution(6, 6, { {2,2,5,4},{3,3,6,6},{5,1,6,3} });
    return 0;
}