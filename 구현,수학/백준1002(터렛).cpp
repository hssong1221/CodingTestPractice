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

//���� �����
/*std::ios_base::sync_with_stdio(false);
std::cin.tie(NULL);*/

using namespace std;


// �� ���� ����� ����, ����(����, ����), �ȸ���(�ܺ�, ����, ���ɿ�) �ؼ� 6���� + �Ϻ��ϰ� ��ġ�³�
int main(void) {
    //�Է�
    int tcase;
    cin >> tcase;

    int x1, y1, r1, x2, y2, r2;
    for (int i = 0; i < tcase; i++) {
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

        if (x1 == x2 && y1 == y2 && r1 == r2) {
            cout << -1 << "\n";
            continue;
        }

        // ���� �Ÿ� ���ϱ�
        double range = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

        // �������� ���� ��
        if (abs(r1 - r2) < range && range < r1 + r2)
            cout << 2 << "\n";
        // �������� ���� ��(����)
        else if (range == r1 + r2)
            cout << 1 << "\n";
        // ����
        else if (range == abs(r1 - r2))
            cout << 1 << "\n";
        // �ȸ����� (�ܺ�)
        else if (r1 + r2 < range)
            cout << 0 << "\n";
        // ����
        else if (range < abs(r1 - r2))
            cout << 0 << "\n";
        // ���ɿ�
        else if (range == 0 && r1 != r2)
            cout << 0 << "\n";
        // ��ġ�� ��
        else if (range == 0 && r1 == r2)
            cout << -1 << "\n";
        else
            cout << "error" << "\n";

    }
    return 0;
}
