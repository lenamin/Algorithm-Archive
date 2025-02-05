#include <bits/stdc++.h>
using namespace std;

stack<int> stk;

int main() {
    // 배열을 돌면서 해당 번째보다 오른쪽에 있는 것 중 (처음 만나는) 해당 번째보다 큰 수
    int n;
    
    cin >> n;
    
    vector<int> nums(n + 1); 
    vector<int> nge(n + 1, -1); // 오큰수 저장할 벡터
    
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    stk.push(0); // 초기값 넣어주기 

    for (int i = 1; i < n; i++) {
        while (!stk.empty() && nums[stk.top()] < nums[i]) {
            nge[stk.top()] = nums[i];
            stk.pop();
        }
        stk.push(i);
    }


    for (int i = 0; i < n; i++) {
        cout << nge[i] << " ";
    }
}