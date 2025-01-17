#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    string star = "*";
    string space = " ";

    for (int i = 1; i <= n; i++) {
        for (int j = n - i; j > 0; j--) {
            cout << space;
        }
        for (int j = 2 * i - 1; j > 0; j--) {
            cout << star;
        }
        cout << '\n';
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            cout << space;
        }

        for (int j = 2 * (n - i) - 1; j > 0; j--) {
            cout << star;
        }


        cout << '\n';
    }
    
}