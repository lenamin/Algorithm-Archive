#include <bits/stdc++.h>
using namespace std;

// 1) 맵에 높이 입력받는다 
// 2) 아 이거 connected components 문제네! 

int n;
int a[104][104];
int f[104][104];
int visited[104][104];
vector<int> ret;
int cnt = 0;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

void dfs(int y, int x) {
    visited[y][x] = 1;
    
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
        if (visited[ny][nx] == 1) continue;
        if (f[ny][nx] == 0) continue;

        dfs(ny, nx);
    }
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int tmp;
            cin >> tmp;
            a[i][j] = tmp;
        }
    }

    // 1부터 n까지 반복하면서 
    // 비가 1만큼 왔을 때, 2만큼 왔을 때, ..., 각 n만큼 왔을 때 등 모두 해보고 
    // 각 지점에서 connected componenets 가 가장 큰 값을 찾는 거구나 
    
    for (int k = n; k >= 0; k--) {
        cout << "k가 " << k << "일 때" << " " << endl;
        memset(f, 0, sizeof(f));
        memset(visited, 0, sizeof(visited));
        cnt = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j] <= k) { 
                    f[i][j] = 1; // 1이면 잠긴다 // 0이면 안잠기는 것

                    if (visited[i][j] == 0) {
                        cnt++;
                        dfs(i, j);
                    }
                // cout << "k: " << k << " " << a[i][j] << " ";
                // cout << f[i][j] << " ";
                }
            }
            // cout << endl;
        }

        cout << "cnt: " << cnt << endl;
        // cout << endl;
    }
    

}