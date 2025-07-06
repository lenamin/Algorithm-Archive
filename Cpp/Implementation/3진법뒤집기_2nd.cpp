#include <bits/stdc++.h>
using namespace std;

string toBase3(int n) {
    if (n == 0) { return ""; }
    char c = n % 3 + '0';
    return toBase3(n / 3) + c;
}

int solution(int n) {
    int answer = 0;
    
    string s = toBase3(n);
    // reverse(s.begin(), s.end());
    cout << s << '\n';
    
    for (int i = 0; i < s.size(); i++) {
        // cout << pow(3, i) * s[i] << '\n';
        // cout << "s[i]: " << s[i] << '\n';
        int k = s[i] - '0';
        cout << "k: " << k << '\n';
        answer += (pow(3, i) * k);
    }
    
    
    return answer;
}