#include<bits/stdc++.h>
using namespace std;

int mps[104][104];
int visited[104][104];
int dists[104][104];

int n, m;

int dx[4] = { 1, -1, 0, 0};
int dy[4] = { 0, 0, 1, -1};

int bfs(int a, int b) {
    queue<pair<int, int>> q;
    q.push({a, b});
    
    visited[a][b] = 1;
    
    while (!q.empty()) {
        pair<int, int> cq = q.front();
        int cx = cq.first;
        int cy = cq.second;
        
        q.pop();
        
        if (cx == n - 1 && cy == m - 1) {
            return dists[cx][cy] + 1;
        }
        
        
        for (int i = 0; i < 4; i++) {
            
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            
            if (nx < 0 || ny < 0 || nx > n || ny > m) { continue; }
            if (mps[nx][ny] == 0) { continue; }
            if (visited[nx][ny]) { continue; }
            
            q.push({nx, ny});
            dists[nx][ny] = dists[cx][cy] + 1;
            visited[nx][ny] = 1;
            
        }
    }
    return -1;
}

int solution(vector<vector<int> > maps)
{
    n = maps.size();
    m = maps[0].size();
    
    int answer = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            mps[i][j] = maps[i][j];
        }
    }
    
    answer = bfs(0, 0);
    
    return answer;
}

int main() {
    vector<vector<int>> maps = {
        {1, 0, 1, 1, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 1, 0, 1},
        {1, 1, 1, 0, 1},
        {0, 0, 0, 0, 1}
    };
    
    cout << solution(maps) << endl; // Expected output: 11
    return 0;
}