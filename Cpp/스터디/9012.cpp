// 3월 1주차 괄호
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        stack<int> stk, rstk; // for 문 안에서 초기화해줘야 더미값이 안들어감 

        for (char c : s) {
            if (c == '(') {
                stk.push(c);
            } else if (c == ')') {
                if (!stk.empty()) { // "(" 가 있어서 짝지어 줄 수 있을 때 
                    stk.pop();
                } else { // 비어있어서 당장은 짝지을 수 없을 때 
                    if (rstk.empty()) { // rstk에도 없으면 넣어주기 
                        rstk.push(c);
                    }
                }
            }
        }
        if (stk.empty() && rstk.empty()) cout << "YES" << '\n';
        else if (!stk.empty() || !rstk.empty()) cout << "NO" << '\n';
    }
}