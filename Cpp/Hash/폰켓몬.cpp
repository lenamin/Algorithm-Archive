// 프로그래머스 폰켓몬 

// 첫번째 코드 
#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> nums)
{
    unordered_map<int, int> mp(nums.size() + 1); // {번호, 해당 번호의 개수}
    int answer = 0;
    
    for (int i = 0; i < nums.size(); i++) {
        mp[nums[i]] += 1;
    }
    
    int n = nums.size() / 2; // 내가 가질 수 있는 폰켓몬의 개수 
    
    for (auto m : mp) {
        if (answer == n) {
            break;
        }
        answer++;
    }
    
    return answer;
}

int solution2(vector<int> nums) {
    unordered_set<int> st(nums.begin(), nums.end());
    int answer = 0;

    return min(st.size(), nums.size() / 2);
}

int main() {
    cout << solution({3, 3, 2, 2, 2, 2});
    cout << solution2({3, 3, 2, 2, 2, 2});
}