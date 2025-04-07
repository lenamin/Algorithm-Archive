#include <bits/stdc++.h>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    // number를 하나씩 순회하다가, 뒤에것이 앞에것보다 더 크면 버려 
    // 앞에거가 더 크면 일단 keep 해둬, 
    // 그리고 새로운 숫자를만날 때 keep 해둔 것, 당장 앞에 있는 것보다 더 큰 젤 큰 숫자가 나타나면 다 버려 
    // 버릴때마다 카운트해서 k보다 같아지면 종료 
    
    stack<char> stk;

    for (char n : number) {
        while (!stk.empty() && k > 0 && stk.top() < n) {
            stk.pop();
            k--;
         }
        stk.push(n);
    }
    
    while (!stk.empty()) {
        answer += stk.top();
        stk.pop();
    }

    reverse(answer.begin(), answer.end());
    
    if (k > 0) {
        answer = answer.substr(0, answer.length() - k);
    } // 리버스 이후에 잘라줘야 원하는 위치의 문자를 자를 수 있다 
    
    
    return answer;
}