#include <bits/stdc++.h>
using namespace std;

int d[1001][1001];

int main() {
    int n, k;
    cin >> n >> k;

    for (int i = 0; i <= n; i++) {
        // 초기화 
        d[i][1] = i;
        d[i][0] = 1;
        d[i][i] = 1;
        
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            d[i][j] = d[i-1][j] + d[i-1][j-1];
            d[i][j] %= 10007;
        }
    }
    
    cout << d[n][k];

}