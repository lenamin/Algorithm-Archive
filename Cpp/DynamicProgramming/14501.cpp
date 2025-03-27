#include <bits/stdc++.h>
using namespace std;

// int day[16][16];
// int sal[16][16];

// bool taken = false; // 이 변수는 굳이 필요가 없다. 

int main() {
    int n;
    cin >> n;

    vector<int> dp(n + 2, 0);

    vector<int> day(n + 1);
    vector<int> sal(n + 1);

    for (int i = 0; i < n; i++) {
        cin >> day[i] >> sal[i];
    }

    for (int i = n - 1; i >= 0; i--) {
        // cout << day[i] << ", " << sal[i] << '\n';
        
        if (i + day[i] > n) {
            dp[i] = dp[i + 1];
        } else if (i + day[i] <= n) {
            dp[i] = max(sal[i] + dp[i + day[i]], dp[i + 1]);
        }
        
    }
    cout << dp[0];
    return 0;


}