#include <bits/stdc++.h>
using namespace std;

int n, k;
map<string, string> mp;

int main() {
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        string ad, pw;
        cin >> ad >> pw;
        mp.insert({ad, pw});
    }

    for (int i = 0; i < k; i++) {
        string s;
        cin >> s;

        cout << mp[s] << '\n';
    }
}