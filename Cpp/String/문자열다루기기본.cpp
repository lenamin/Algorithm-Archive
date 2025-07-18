#include <bits/stdc++.h>

using namespace std;

bool solution(string s) {
    bool answer = true;
    bool isd = true;
    int cnt = 0;
    
    // 숫자인지 체크 
    for (int i = 0; i < s.size(); i++) {
        cnt++;
        if (!isdigit(s[i])) {
             isd = false;   
        }
    }
    if (cnt == 4 || cnt == 6) {
        if (isd) { return true; }
        return false;
    }
    return false;
}

int main() {
    string s = "1234";
    
    cout << solution(s) << endl; // Output: 1 (true)
    
    s = "12345";
    cout << solution(s) << endl; // Output: 0 (false)
    
    s = "123a";
    cout << solution(s) << endl; // Output: 0 (false)
    
    return 0;
}