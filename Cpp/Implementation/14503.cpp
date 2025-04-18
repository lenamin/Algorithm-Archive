#include <bits/stdc++.h>
using namespace std;

int n, m; // 방 크기 (가로, 세로)
int r, c, d; // 로봇청소기의 초기 위치
int cnt; // 청소횟수 카운트 
int room[54][54];
bool visited[54][54];
pair<int, int> bot;

int dr[4] = {-1, 0, 1, 0}; // 북 동 남 서 d가 = 0, 1, 2, 3일 때 이동해야 할 방향 
int dc[4] = {0, 1, 0, -1}; // 북 동 남 서 d가 = 0, 1, 2, 3일 때 이동해야 할 방향 

int main() {
    cin >> n >> m;
    cin >> r >> c >> d;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> room[i][j];
        }
    }
    
    bot = {r, c}; // 로봇청소기의 초기 위치 잡아주기

    while (true) {
        
        if (!visited[r][c]) {
            visited[r][c] = true;
            cnt++;
        }
        bool ismoved = false;
            
        for (int i = 0; i < 4; i++) {
            d = (d + 3) % 4;

            int nx = r + dr[d];
            int ny = c + dc[d];

            if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
                if (!visited[nx][ny] && room[nx][ny] == 0) {
                    r = nx;
                    c = ny;
                    ismoved = true;
                    break;
                }
            }
        }
        if (!ismoved) { // 후진시도
            int back = (d + 2) % 4;
            int bx = r + dr[back];
            int by = c + dc[back];

            if (bx >= 0 && by >= 0 && bx < n && by < m && room[bx][by] == 0) {
                r = bx;
                c = by;
            } else {
                break;
            }
        }
        
    }
    cout << cnt << '\n';

}