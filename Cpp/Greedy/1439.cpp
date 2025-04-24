#include <bits/stdc++.h>
using namespace std;

int oc = 0;
int tc = 0;

int main() {
    string s;
    cin >> s;

    char c = s[0];
    c == '0' ? (oc++) : (tc++);
    for (int i = 1; i < s.length(); i++) {
        if (s[i] != c) {
            c = s[i];
            c == '0' ? (oc++) : (tc++);
        }
    }

    // cout << "oc : " << oc << '\n';
    // cout << "tc : " << tc << '\n';

    if (tc <= oc) {
        cout << tc << '\n';
    } else {
        cout << oc << '\n';
    }
}