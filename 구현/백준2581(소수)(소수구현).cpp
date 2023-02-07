#include <string>
#include <vector>
#include <iostream>
#include <climits>
#include <map>
#include <sstream>
#include <set>
#include <algorithm>
#include <bitset>
#include <deque>
#include <unordered_map>

//빠른 입출력
/*std::ios_base::sync_with_stdio(false);
std::cin.tie(NULL);*/

using namespace std;

bool Prime(int n) {
    if (n < 2)
        return false;

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main(void) {
    int M, N;
    cin >> M >> N;

    int total = 0;
    int min = 0;
    bool flag = true;
    for (int i = M; i <= N; i++) {
        if (Prime(i)) {
            total += i;
            if (flag) { flag = false; min = i; }
        }
    }
    
    if (total == 0)
        cout << -1;
    else
        cout << total << "\n" << min << "\n";

    return 0;
}
