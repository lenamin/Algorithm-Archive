// 백준 1325번 : 효율적으로 해킹하기 

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> arr;
vector<int> visited; // 매번 초기화시켜야 함 
vector<int> ans;

void bfs(int a) {
    queue<int> q;
    q.push(a);
    visited[a] = true;

    while (!q.empty()) {
        int k = q.front();
        q.pop();

        for (int i : arr[k]) {
            if (visited[i] == false) {
                visited[i] = true;
                ans[i]++;
                q.push(i);
            }
        }
    }
}

int main() {
    int v, e;
    cin >> v >> e;
    arr.resize(v + 1);
    visited.resize(v + 1);
    ans.resize(v + 1, 0); // 벡터 초기화 잊지마 
    
    for (int i = 0; i < e; i++) {
        int v1, v2;    
        cin >> v1 >> v2;
        arr[v1].push_back(v2);
    }
    
    // 시작노드를 정해준게 아니고, 모든 노드에 대해서 인접리스트를 돌아야 하므로 반복문에서 bfs를 수행해야 함 
    for (int i = 1; i <= v; i++) {
        fill(visited.begin(), visited.end(), false); // 배열은 memset, 벡터는 fill 
        bfs(i);
    }

    int M = *max_element(ans.begin(), ans.end());
    
    for (int i = 1; i <= v; i++) {
        if (ans[i] == M) {
            cout << i << " ";
        }
    }
}