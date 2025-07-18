#include <bits/stdc++.h>

using namespace std;
char mps[104][104];
int dist[104][104];
int visited[104][104];

int answer = -1;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int n;
int m;

int bfs(char from, char to) {
    answer = -1;
    memset(visited, 0, sizeof(visited));
    memset(dist, 0, sizeof(dist));
    queue<pair<int, int>> q;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            
            if (mps[i][j] == from) {
                // cout << "from " << i << ", " << j << '\n';
                q.push({i, j});
                dist[i][j] = 0;
                visited[i][j] = 1;
            } 
        }
    }

    // if (q.empty()) { return -1;}
    
     while (!q.empty()) {
        pair<int, int> cn = q.front();
        q.pop();
        int cx = cn.first;
        int cy = cn.second;
        
        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            
            if (visited[nx][ny] || nx < 0 || nx >= n || ny < 0 || ny >= m) { continue; }
            if (mps[nx][ny] == 'X') { continue; }
            
            visited[nx][ny] = 1;
            dist[nx][ny] = dist[cx][cy] + 1;
            answer = dist[nx][ny];
            if (mps[nx][ny] == to) { 
                return answer; 
            } else {
                q.push({nx, ny});    
            }
        }
    }
    return -1;
}

int solution(vector<string> maps) {
    
    for (int i = 0; i < maps.size(); i++) {
        n = maps.size();
        for (int j = 0; j < maps[i].size(); j++) {
            m = maps[i].size();
            mps[i][j] = maps[i][j];
        }
    }
    
    int sl = bfs('S', 'L');
    if (sl == -1) {
        return -1;
    }
    int le = bfs('L', 'E');
  
    if (le == -1) {
        return -1;
    }
    

    return sl + le;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    vector<string> maps = {"SOOOL", "XXXXO", "OOOOO", "OXXXX", "OOOOE"};
    cout << solution(maps) << '\n'; // Expected output: 16
    
    return 0;
}