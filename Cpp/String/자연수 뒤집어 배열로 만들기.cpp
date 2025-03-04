/**
 * @file 자연수 뒤집어 배열로 만들기.cpp
 * @brief char 타입을 int로 바꾸는 방법을 잊어먹었다... <br> 잊지말자 char type '3' - '0' = int type 3이 된다. 
 * @date 2025-03-04
 * 
 * 
 */

#include <bits/stdc++.h>

using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;
    stack<char> stk;
    
    // 자연수 뒤집어 배열로 만들기 
    
    string str = to_string(n);
    
    for (char c : str) {
        stk.push(c);
    }
    
    while (!stk.empty()) {
        char s = stk.top();
    
        answer.push_back(s - '0');
        stk.pop();
    }
    return answer;
}