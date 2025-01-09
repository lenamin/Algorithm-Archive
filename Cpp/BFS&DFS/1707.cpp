// 이분그래프 판별하기 
#include <bits/stdc++.h>
using namespace std;

int v, e, isBi; // 노드, 에지, 이분그래프여부 
vector<int> check;
vector<vector<int>> g;
vector<int> visited;

void dfs(int a, int c) { // a : vertex, c : color flag 
    visited[a] = 1; // 방문처리 
    check[a] = c; // 해당 노드에 색상 할당해야지 
    
    for (auto i : g[a]) { // 인접노드 방문
        if (visited[i] == 0) { // 아직 방문 안했음면 
            dfs(i, -c);
        } else if (visited[i] == 1 && check[i] == c) {
            isBi = false;
        }
    }
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n; // 테스트케이스 입력받기 

    for (int i = 0; i < n; i++) {
        cin >> v >> e; // 노드, 에지 개수 받기 
       
        g.assign(v + 1, vector<int>());
        visited.assign(v + 1, 0);
        check.assign(v + 1, 0);
        isBi = true;

        for (int j = 0; j < e; j++) {
            int t1, t2;
            cin >> t1 >> t2;
            g[t1].push_back(t2);
            g[t2].push_back(t1);
        }

        for (int k = 1; k <= v; k++) {
            if (visited[k] == 0) {
                dfs(k, 1);
            }
        }

        if (isBi) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }
}