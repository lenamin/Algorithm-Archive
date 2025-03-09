// 피보나치 함수 
#include <bits/stdc++.h>
using namespace std;

int dp[41][2];

void memo(int n) {
    // 초기값 지정해주기 
    
    dp[0][0] = 1; dp[0][1] = 0; // 0일 때
    dp[1][0] = 0; dp[1][1] = 1; // 1일 때

    for (int i = 2; i <= 40; i++) {
        dp[i][0] = dp[i-1][0] + dp[i-2][0];
        dp[i][1] = dp[i-1][1] + dp[i-2][1];
    }

}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    memo(40);

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;

        cout << dp[a][0] << " " << dp[a][1] << '\n';

    }
}