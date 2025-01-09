// 특정 거리의 도시찾기 

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> ad;
vector<int> visited;
vector<int> ans;

void bfs(int a) {
    queue<int> q;
    q.push(a); // 출발노드 추가 
    visited[a]++;

    while (!q.empty()) {
        int k = q.front();
        q.pop(); 
        for (int i : ad[k]) {
            if (visited[i] == -1) {
                visited[i] = visited[k] + 1;
                q.push(i);
            }
        }
    }
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int v, e, d, s; // 도시수, 도로 수, 찾아야하는 최단거리, 시작점 
    cin >> v >> e >> d >> s;
    ad.resize(v+1);
    visited.resize(v+1, -1);

    for (int i = 1; i <= e; i++) {
        int m, n;
        cin >> m >> n;
        ad[m].push_back(n); 
        // ad[n].push_back(m); // 제발 문제 똑바로 읽어!! 단방향그래프잖아 
    }

    bfs(s);
    
    for (int i = 1; i <= v; i++) {
        if (visited[i] == d) {
            ans.push_back(i);
        }
    }

    if (ans.empty()) { cout << -1 << '\n'; }
    else {
        sort(ans.begin(), ans.end());
        for (int a : ans) {
           cout << a << '\n';
        }
    }
}