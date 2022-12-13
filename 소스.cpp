#include <string>
#include <vector>

using namespace std;


string solution(string my_string) {
    string answer = "";
    for (auto m : my_string) {
        if (m >= 97)
            answer += toupper(m);
        else
            answer += tolower(m);
    }
    return answer;
}

int main(void) {
    solution(29423);
    return 0;
}