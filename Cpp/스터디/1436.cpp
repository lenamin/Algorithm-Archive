#include <bits/stdc++.h>
using namespace std;

int main() {
    int cnt;
    cin >> cnt;
    int ans = 0;

    for (int i = 666; i < INT_MAX; i++) {
        if (to_string(i).find("666") != string::npos) {
            ans++;
        }
        if (ans == cnt) { 
            cout << i << '\n'; 
            break;}
    }
}