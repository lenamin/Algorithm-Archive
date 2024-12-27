#include <bits/stdc++.h>
using namespace std;

int vertex, edge;
vector<list<int>> relationships;
vector<bool> visited(false);
int cnt;

void dfs(int current) {
    // cout << "dfs가 호출되었다" << endl;
    visited[current] = true; // 방문처리
    
    for (auto r : relationships[current]) {
        // cout << "current와 연결되어있는 컴퓨터 vertex : " << r << endl;
        if (visited[r] == 1) { continue; }
        dfs(r);
        cnt++;
    }
}

int main() {
    
    cin >> vertex; // 총 컴퓨터의 수 
    cin >> edge; // 바이러스에 걸린 컴퓨터의 수
    
    relationships.resize(vertex + 1);
    visited.resize(vertex + 1);

    // 인접리스트로 입력받기 
    for (int i = 1; i <= edge; i++) {
        int s, e;
        cin >> s >> e;
        relationships[s].push_back(e);
        relationships[e].push_back(s);
    }

    // cout << vertex << endl;
    dfs(1);
    cout << cnt << '\n';
    
}