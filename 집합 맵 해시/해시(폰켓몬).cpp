#include <vector>
#include <iostream>
#include <map>

using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    map<int, int> phoneketmon;

    // 종류마다 갯수
    for (int i = 0; i < nums.size(); i++) {
        if (phoneketmon[nums[i]] == 0) {
            phoneketmon[nums[i]] = 1;
        }
        else {
            phoneketmon[nums[i]]++;

        }
    }

    // 가져가는 갯수보다 종류가 더 많다면 어차피 최대개수
    // 가져가는 갯수가 더 많다면 최대 종류만큼만 가져갈수있음
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

/* 20221212 재구현
int solution(vector<int> nums) {
    int answer = 0;
    map<int, int> pmon;

    for (auto n : nums)
        pmon[n]++;
    
    answer = min(nums.size() / 2, pmon.size());

    return answer;
}*/