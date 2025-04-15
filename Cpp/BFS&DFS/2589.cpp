#include <bits/stdc++.h>
using namespace std;

char pr[54][54];
bool visited[54][54];

int n, m;
int cnt = 0;
static int mcnt = 0;
typedef tuple<int, int, int>  pt; // x좌표, y좌표, 거리
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

void bfs(int x, int y) {

    queue<pt> q;
    
    q.push({x, y, 0});
    visited[x][y]= true;
    cnt = 0;

    while (!q.empty()) {
        int cx, cy, dt;
        tie(cx, cy, dt) = q.front(); 
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx >= n || ny >= m || nx < 0 || ny < 0) { continue; }

            if (!visited[nx][ny] && pr[nx][ny] == 'L') {
                visited[nx][ny] = true;
                q.push({nx, ny, dt + 1});
                mcnt = max(mcnt, dt + 1);
            }
        }
    }
}

int main() {
    // 1. 일단 입력을 받자 
    
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            pr[i][j] = s[j];
            
        }
    }
    // 2. 그리고 BFS를 돌려서 모든 L에 대해서 갈 수 있는지 체크 / 매번 최대값 갱신 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) { 
            if (pr[i][j] == 'L') {
                memset(visited, false, sizeof(visited)); // 이전에 방문했떤 visited 여부 초기화해주기 
                bfs(i, j);
            }
            
        }
    }
    cout << mcnt << '\n';
}