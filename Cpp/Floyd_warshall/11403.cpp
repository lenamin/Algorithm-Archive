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
    // k가 중간경로. i - k 경로가 존재하고, k - j 간 경로가 존재하면 
    // 결국 i - j 경로도 존재하는거니까 adj[i][j] 값 갱신해줄 수 있는 것 
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