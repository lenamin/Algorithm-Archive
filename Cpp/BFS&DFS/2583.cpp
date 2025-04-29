#include <bits/stdc++.h>
using namespace std;

int r, c, n; // row, column, 직사각형개수
int arr[104][104];
vector<vector<bool>> visited(104, vector<bool>(104, false));
vector<int> answers; // 넓이 저장할 배열 

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void dfs(int y, int x, int &count) {
    visited[y][x] = true;
    count++;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && ny >= 0 && nx < c && ny < r && !visited[ny][nx] && arr[ny][nx] != 1) {
            dfs(ny, nx, count);
        }
    }
}

int main() {
    cin >> r >> c >> n;
    
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        
        for (int y = y1; y < y2; y++) {
            for (int x = x1; x < x2; x++) {
                arr[y][x] = 1;
            }
        }
    }
    
    int cc = 0; // connected components 개수 세는 변수 
    int cnt = 0; // 각 면적 구하는 변수            
    
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (!visited[i][j] && arr[i][j] == 0) {
                
                dfs(i, j, cnt);
                cc++;
                answers.push_back(cnt);
                cnt = 0;
            }
            
        }
    }

    cout << cc << '\n';
    sort(answers.begin(), answers.end());

    for (int a : answers) {
        cout << a << ' ';
    }
}