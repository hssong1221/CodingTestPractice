#include <string>
#include <vector>
#include <iostream>

using namespace std;

void DFS(string begin, string target, vector<string> words, vector<int> visit, int num);

int answer = 0;

int solution(string begin, string target, vector<string> words) {
    vector<int> visit(51,0);
    DFS(begin, target, words, visit, 0);

    cout << "answer : " << answer;
    return answer;
}
void DFS(string begin, string target, vector<string> words, vector<int> visit, int num) {
    if (begin == target) {
        answer = num;
        return;
    }

    for (int i = 0; i < words.size(); i++) {
        for (auto v : visit)
            cout << v << " ";
        cout << endl;

        cout << begin << " " << words[i] << endl;
        cout << num << endl;
        
        if (begin == words[i]) 
            continue;
        else if(begin != words[i] ) {
            int temp = 0;
            for (int k = 0; k < words[i].size(); k++) {
                if (temp > 1)
                    break;

                if (visit[i] == 1) 
                    continue;

                if (begin[k] != words[i][k])
                    temp++;

                cout << begin[k] << " " << words[i][k] << endl;
                cout << temp << endl;
            }

            if (temp == 1 ) {
                visit[i] = 1;
                DFS(words[i], target, words, visit, num + 1);
            }
        }
    }
}
int main() {
    solution("hit", "hhh", { "hhh", "hht" });
    return 0;
}