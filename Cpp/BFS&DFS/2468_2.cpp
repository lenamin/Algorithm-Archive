#include <bits/stdc++.h>
using namespace std;

int arr[104][104];
bool visited[104][104];

int n;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int maxHeight = 0;

void dfs(int x, int y, int height) {
    visited[x][y] = true;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && ny >= 0 && nx < n && ny < n && !visited[nx][ny] && arr[nx][ny] > height) {
            dfs(nx, ny, height);
        }
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];

            if (arr[i][j] > maxHeight) {
                maxHeight = arr[i][j];
            }
        }
    }
    
    int maxSafeArea = 0;

    for (int rainHeight = 0; rainHeight <= maxHeight; rainHeight++) {
        memset(visited, false, sizeof(visited));
        
        int sa = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (arr[i][j] > rainHeight && !visited[i][j]) {
                    dfs(i, j, rainHeight);
                    sa++;
                }
            }
        }
        maxSafeArea = max(maxSafeArea, sa);
    }

    cout << maxSafeArea << '\n';
}