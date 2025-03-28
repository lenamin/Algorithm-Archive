#include <bits/stdc++.h>
using namespace std;
int n;
int m = INT_MAX;
vector<bool> visited; // true는 스타트팀, false는 링크팀 
int ps[20][20];

void dfs(int idx, int depth) {
    if (depth == n / 2) {
        
        int ssum = 0; 
        int lsum = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (visited[i] && visited[j]) {
                    ssum += ps[i][j] + ps[j][i];
                } else if (!visited[i] && !visited[j]) {
                    lsum += ps[i][j] + ps[j][i];
                }
            }
        }

        int tmp = abs(lsum - ssum);
        if (tmp < m) {
            m = tmp;
        }
        return;
    }

    for (int i = idx; i < n; i++) {
        // if (!visited[i]) {
            visited[i] = true; // start 팀으로 만들어주기 
            dfs(i + 1, depth + 1); 
            visited[i] = false; // 다 탐색하고 원상복구!!!!!! 
        // }
    }
}

int main() {
    
    cin >> n;

    visited.resize(n, false);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> ps[i][j];
        }
    }

    dfs(0, 0);
    cout << m << '\n';
}