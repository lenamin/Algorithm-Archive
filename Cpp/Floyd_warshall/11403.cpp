#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> adj;
vector<vector<int>> answers;

int main() {
    cin >> n;

    adj.resize(n, vector<int>(n));
    answers.resize(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> adj[i][j];
        }
    }

    // 경로있는지 확인하는 플로이드워셜 알고리즘 
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (adj[i][k] && adj[k][j]) {
                    adj[i][j] = 1;
                }   
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << adj[i][j] << " ";
        }
        cout << '\n';
    }
}