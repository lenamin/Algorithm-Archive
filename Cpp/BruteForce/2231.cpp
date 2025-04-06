#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int tmp = i;
        string s = to_string(i);

        for (char c : s) {
            tmp = tmp + (c - '0');
        }

        if (tmp == n) {
            cout << i << '\n';
            break;
        }

        if (i == n) {
            cout << 0 << '\n';
        }
    }
}