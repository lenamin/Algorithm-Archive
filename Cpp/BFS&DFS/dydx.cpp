#include <bits/stdc++.h>
using namespace std;

// 네 방향으로 이동 
/*
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int main() {
    int y = 0, x = 0;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        cout << ny << " : " << nx << endl;
    }
    return 0;
}
*/

// 8방향으로 이동 
/*
int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};

int main() {
    int x = 0, y = 0;
    for (int i = 0; i < 8; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        cout << ny << " : " << nx << endl;
    }
}*/

// 1) 3x3 맵 입력받기 
// 2) dy, dx 설정하기 
// 3) 각 정점 방문하면서 

const int r = 3;
int my[r][r], visited[r][r];
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

void go(int y, int x) {

    visited[y][x] = 1;
    cout << y << " , " << x << endl;

    for (int i = 0; i < 4; i++) {    
        
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= r || nx >= r) { continue; }
        if (my[ny][nx] == 0) { continue; }
        if (visited[ny][nx] == 1) { continue; }

        go(ny, nx);
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < r; j++) {
            int tmp;
            cin >> tmp;
            my[i][j] = tmp;
        }
    }
    go(0, 0);
}
