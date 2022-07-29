#include <string>
#include <vector>
#include <iostream>

using namespace std;

// �÷��̵� ���� �˰���
// ��� ��ο��� �ִܰŸ��� ���ϴ� �˰���
// � ��� n�� ������ ���� �Ȱ����� �� ����ġ�� ���ؼ� �� ª�� �Ÿ��� ��� ������
// ex) ���� i->j �� i->k->j ���� ��� ����
// ���������� (i, j) (j, k) �� i�� k�� �̱����

int solution(int n, vector<vector<int>> results) {
    int answer = 0;

    // ������� ����ϰ� �̱�� 1 ���� 0 ���ֱ�
    vector<vector<int>> rank(102 , vector<int>(102 , 0));
    for (int i = 0; i < results.size(); i++) {
        rank[results[i][0]][results[i][1]] = 1;
        rank[results[i][1]][results[i][0]] = -1;
    }
    
    // 1���� ����
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                // ��� ����� ��� 0�ΰ��߿��� ���������� �˼� �ִ°� ã��
                if (rank[j][k] == 0) {
                    if (rank[j][i] == 1 && rank[i][k] == 1) 
                        rank[j][k] = 1;
                    else if (rank[j][i] == -1 && rank[i][k] == -1)
                        rank[j][k] = -1;
                }
            }
        }
    }

    // �ڱ� �ڽ� ���� ���� �̱�ų� ���� Ȯ���Ǹ� ������ ������
    for (int i = 1; i <= n; i++) {
        int temp = 0;
        for (int j = 1; j <= n; j++) {
            cout << rank[i][j] << " ";
            if (rank[i][j] == 0)
                temp++;
        }
        cout << endl;
        if (temp == 1)
            answer++;
    }

    cout << answer;
    return answer;
}

int main() {
    solution(5, { {1,2},{4,5},{3,4},{2,3} });
    return 0;
}