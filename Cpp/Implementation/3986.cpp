#include <bits/stdc++.h>
using namespace std;

int n, cnt;

int main() {
    
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        stack<int> stk;
        stk.push(s[0]);

        for (int j = 1; j < s.length(); j++) {
            if (!stk.empty() && s[j] == stk.top()) {
                stk.pop();
            } else {
                stk.push(s[j]);
            }
        }

        if (stk.empty()) cnt++;
    }
    cout << cnt << '\n';
}