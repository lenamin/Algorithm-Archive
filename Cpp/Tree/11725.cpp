// 트리의 부모 찾기 

#include <bits/stdc++.h>
using namespace std;

vector<bool> visited;
vector<vector<int>> tree;
vector<int> answer;

void dfs(int a);

int main() {
    int n; 
    cin >> n;
    
    visited.resize(n + 1);
    tree.resize(n + 1);
    answer.resize(n + 1);

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    dfs(1);

    for (int i = 2; i <= n; i++) {
        cout << answer[i] << '\n';
    }
    
}

void dfs(int a) {
    visited[a] = true;

    for (auto next : tree[a]) {
        if (!visited[next]) {
            answer[next] = a;
            dfs(next);
        }
        
    } 
}