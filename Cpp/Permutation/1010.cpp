#include <bits/stdc++.h>
using namespace std;

int d[31][31];

int main() {
    int m;
    cin >> m;
    
    for (int i = 0; i <= 30; i++) {
        d[i][1] = i;    
        d[i][0] = 1;
        d[i][i] = 1;
    }

    for (int i = 2; i <= 30; i++) {
        for (int j = 1; j < i; j++) {
            d[i][j] = d[i-1][j] + d[i-1][j-1];
        }
    }

    for (int i = 0; i < m; i++) {
        int n, k;
        cin >> n >> k;
        cout << d[k][n] << '\n';
    }
}