#include <bits/stdc++.h>
using namespace std;

vector<int> dp(11, 0);

int count(int n) {
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    for (int i = 4; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }
    
    return dp[n];
}

int main() {
 
    int n;
    cin >> n;

    // f(n) = f(n-1) + f(n-2) + f(n-3);

    count(11);

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        
        cout << dp[a] << '\n';

    }

}