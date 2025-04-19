#include <bits/stdc++.h>
using namespace std;

int n, m;
char board[54][54];
vector<vector<bool>> visited;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
static bool isCycle = false;

void dfs(int x, int y, int px, int py) {
    visited[x][y] = true; // 방문처리 
    char dot = board[x][y];

    for (int i = 0; i < 4; i++) { // 시작점에서 네 방향을 모두 확인할거야 
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (dot == board[nx][ny]) {
            if (nx >= 0 && ny >= 0 && nx < n && ny < m) {  // 순회할 nx, ny가 일단 범위 내에 있는지 처리해야지 
            char nc = board[nx][ny];
            
                if (visited[nx][ny] && !(ny == py && nx == px)) {
                    isCycle = true;
                    return;
                } 
                if (!visited[nx][ny]) {
                    dfs(nx, ny, x, y);
                }
            }
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
    visited.resize(n, vector<bool>(m, false));
    // !visited 인 모든 점 방문을 하면서 
    // dfs 로직에서 시작 좌표를 기억해뒀다가, 다시 시작좌표를 만나면 그 때 break 하고 "YES" 출력 
    // 그럼 visited를 nx, ny를 검사한 이후에 처리해야겠네? 
    // 다음으로 넘어가는 조건은 nx != cx, ny != cy 가 되면 되겠다 
    // => 이거 아님!!!! 이러면 백트래킹했을 때인 경우도 cycle이라고 잘못 탐지할 수 있음 

    // 같은 곳으로 오는데, 다른 경로를 통해 올 때! 싸이클이라고 판별한다 ! 

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j]) {
                dfs(i, j, i, j);
                if (isCycle) break;
            }
        }
        if (isCycle) break;
    }
    if (isCycle) { cout << "Yes" << '\n'; } else { cout << "No" << '\n'; }
}