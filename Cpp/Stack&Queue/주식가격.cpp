#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(), 0);    
    stack<int> stk;
    /*
    for (int i = 0; i < prices.size(); i++) {
        int now = prices[i];
        
        for (int j = i + 1; j < prices.size(); j++) {
            if (now <= prices[j]) {
                answer[i]++;
            } else if (prices[j] < now) {
                break;
            }
            
        }
    } 시간초과 버전 */ 
    
    for (int i = 0; i < prices.size(); i++) {
        while (!stk.empty() && prices[stk.top()] > prices[i]) {
            answer[stk.top()] = i - stk.top();
            stk.pop();
        }
        stk.push(i);
    }
    

    while (!stk.empty()) {
        answer[stk.top()] = prices.size() - stk.top() - 1;
        stk.pop();
    }
    
    return answer;
}