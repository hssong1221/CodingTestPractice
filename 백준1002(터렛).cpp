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


// 두 원의 관계는 두점, 한점(외접, 내접), 안만남(외부, 내부, 동심원) 해서 6종류 + 완벽하게 겹치는놈
int main(void) {
    //입력
    int tcase;
    cin >> tcase;

    int x1, y1, r1, x2, y2, r2;
    for (int i = 0; i < tcase; i++) {
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

        if (x1 == x2 && y1 == y2 && r1 == r2) {
            cout << -1 << "\n";
            continue;
        }

        // 두점 거리 구하기
        double range = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

        // 두점에서 만날 때
        if (abs(r1 - r2) < range && range < r1 + r2)
            cout << 2 << "\n";
        // 한점에서 만날 때(외접)
        else if (range == r1 + r2)
            cout << 1 << "\n";
        // 내접
        else if (range == abs(r1 - r2))
            cout << 1 << "\n";
        // 안만날때 (외부)
        else if (r1 + r2 < range)
            cout << 0 << "\n";
        // 내부
        else if (range < abs(r1 - r2))
            cout << 0 << "\n";
        // 동심원
        else if (range == 0 && r1 != r2)
            cout << 0 << "\n";
        // 겹치는 놈
        else if (range == 0 && r1 == r2)
            cout << -1 << "\n";
        else
            cout << "error" << "\n";

    }
    return 0;
}
