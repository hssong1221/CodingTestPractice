#include <vector>
#include <iostream>
#include <map>

using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    map<int, int> phoneketmon;

    // �������� ����
    for (int i = 0; i < nums.size(); i++) {
        if (phoneketmon[nums[i]] == 0) {
            phoneketmon[nums[i]] = 1;
        }
        else {
            phoneketmon[nums[i]]++;

        }
    }

    // �������� �������� ������ �� ���ٸ� ������ �ִ밳��
    // �������� ������ �� ���ٸ� �ִ� ������ŭ�� ������������
    if ((nums.size() / 2) <= phoneketmon.size())
        answer = nums.size() / 2;
    else    
        answer = phoneketmon.size();

    cout << answer;
    return answer;
}

int main() {
    solution({ 3,1,2,3 });
    return 0;
}

/* 20221212 �籸��
int solution(vector<int> nums) {
    int answer = 0;
    map<int, int> pmon;

    for (auto n : nums)
        pmon[n]++;
    
    answer = min(nums.size() / 2, pmon.size());

    return answer;
}*/