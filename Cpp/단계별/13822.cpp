// 더하기 

#include <bits/stdc++.h>
using namespace std;

int main() {
    int cnt = 0;
    string s1;
    string s2;
    cin >> s1;

    for (char c : s1) {
        if (c != ',') {
            s2.push_back(c);
        } else if (c == ',') {
            cnt += stoi(s2);
            s2 = "";
        } 
    }

    cnt += stoi(s2);

    cout << cnt << '\n';
}