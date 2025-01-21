#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> ajlist;
vector<bool> visited;

void dfs(int now) {
    if (visited[now]) return;
    visited[now] = true;
    cout << now << " ";

    for (int next : ajlist[now]) {
        if (!visited[next]) {
            dfs(next);
        }
    }
}

void bfs(int a) {
    queue<int> q;
    q.push(a);
    visited[a] = true;
    cout << a << " ";

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        for (int next : ajlist[now]) {
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
                cout << next << " ";
            }
        }
    }
}

int main() {
    int v, e, s;
    cin >> v >> e >> s;

    ajlist.resize(v + 1);
    visited.resize(v + 1);

    for (int i = 0; i < e; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        ajlist[v1].push_back(v2);
        ajlist[v2].push_back(v1);
    }

    for (int i = 1; i < v + 1; i++) {
        sort(ajlist[i].begin(), ajlist[i].end());
    }

    dfs(s);
    fill(visited.begin(), visited.end(), false);
    cout << '\n';
    bfs(s);
}