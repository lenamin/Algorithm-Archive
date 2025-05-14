#include <bits/stdc++.h>
using namespace std;

int m, n;
vector<vector<int>> arr;
vector<vector<int>> visited;
queue<pair<int, int>> q;
vector<pair<int, int>> cheese; // 치즈가 있는 배열을 저장할 배열 

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

int hour = 0;
int lastCC = 0;

void bfs(int y, int x) {
    visited[y][x] = 1; // 현재 좌표 방문했습니다 도장 쾅쾅 

    q.push({y, x}); // 탐색할 노드를 큐에 삽입 

    while (!q.empty()) {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();
        // 지금 좌표의 네 방향을 살펴보자 
        for (int i = 0; i < 4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            // 1) 여기서 배열 범위 벗어나지 않았는지 체크 
            // 2) 방문한적 있는지 체크 
            // 3) 공기인지 치즈인지 체크 
            if (ny < m && nx < n && ny >= 0 && nx >= 0) { // 유효한 범위고
                if (visited[ny][nx] == 0) { // 방문한 적 없으면 
                    if (arr[ny][nx] == 0) { 
                        q.push({ny, nx});
                        visited[ny][nx] = 1;
                    } else {
                        // 치즈니까 녹일 후보로 저장해야한다 
                        cheese.push_back({ny, nx});

                    }
                }
            }
        }
    }
}

int main() {
    cin >> m >> n;

    arr.resize(m, vector<int>(n));
    visited.resize(m, vector<int>(n));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 1) {
            }
        }   
    }
    

    while (true) {
        
        int cnt = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (arr[i][j] == 1) {
                    cnt++;
                }
            }
        }

        if (cnt == 0) { break; } // lastCC 가 0이면 반복종료 
        else { lastCC = cnt; }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                visited[i][j] = 0;
            }
        }
        cheese.clear();

        bfs(0, 0);
        for (auto c : cheese) {
            int r = c.first;
            int cl = c.second;

            arr[r][cl] = 0;
        }
        hour++;
    }

    cout << hour << '\n';
    cout << lastCC << '\n';
}