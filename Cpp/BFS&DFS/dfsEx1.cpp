// 종화는 방구쟁이야 
// connected component 문제 

#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[104][104];
int visited[104][104];
const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1};
int cnt = 0;

void go(int y, int x) {
    // DFS 로 구현 
    // 1) : 방문한다 
    // 2) : 

    visited[y][x] = 1;
    cout << x << ", " << y << endl;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= n || nx >= m) { continue; } // 더 이상 없으니까 
        if (a[ny][nx] == 0) { continue; }
        if (visited[ny][nx] == 1) { continue; }

        go (ny, nx);
    }
}

int main() {

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (visited[i][j] == 0 && a[i][j] == 1) { 
                cnt += 1;
                go(i, j);
             }
        }
    }
    cout << "cnt 는: " << cnt << endl;
}