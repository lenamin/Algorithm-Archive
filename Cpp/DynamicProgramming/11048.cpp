#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> miro;
vector<vector<int>> dp;

int main() {
    cin >> n >> m;

    miro.resize(n, vector<int>(m, 0));
    dp.resize(n, vector<int>(m, 0));

    // 일단 미로 입력받아 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> miro[i][j];
        }
    }

    // DP니까 점화식을 구해야지 
    // dp[r][c] = max(dp[r+1][c], dp[r][c + 1], dp[r+1][c+1])
    // 이건 역방향임. 정방향으로 짜자! 

    dp[0][0] = miro[0][0];
    // 첫번째 행 초기화 
    for (int j = 1; j < m; j++) {
        dp[0][j] = dp[0][j - 1] + miro[0][j];
    }

    for (int i = 1; i < n; i++) {
        dp[i][0] = dp[i - 1][0] + miro[i][0];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            dp[i][j] = max({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + miro[i][j];
        }
    }

    cout << dp[n-1][m-1] << '\n';
}