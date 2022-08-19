#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<string> answer;
vector<int> visited(100001, 0);
bool visit = false;
int index = 0;

void DFS(vector<vector<string>> tickets, string start) {
    if (index == tickets.size())
        visit = true;

    answer.push_back(start);

    for (int i = 0; i < tickets.size(); i++) {
        if (visited[i] == 0 && tickets[i][0] == start) {
            visited[i] = 1;
            index +=1;
            DFS(tickets, tickets[i][1]);

            if (!visit) {
                answer.pop_back();
                visited[i] = 0;
            }
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(), tickets.end());

    DFS(tickets, "ICN");

    for (auto a : answer)
        cout << a << " ";
    return answer;
}



int main() {
    solution({ {"ICN", "SFO"},{"ICN", "ATL"},{"SFO", "ATL"},{"ATL", "ICN"},{"ATL","SFO"} });
    return 0;
}