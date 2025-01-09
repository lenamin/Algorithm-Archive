#include <bits/stdc++.h>
using namespace std;

// connected componenets 문제 
// dfs로 풀자 

int n;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };

int a, b, k;
int arr[54][54];
int visited[54][54];

void dfs(int y, int x) {
    visited[y][x] = 1; // 방문처리 

    // 네 방향을 돌면서 이동할 수 있는지 확인
    for (int i = 0; i < 4; i++) {
        
        int ny = y + dy[i];
        int nx = x + dx[i];
        // 경계값 조사 1) 언더플로우 2) 오버플로우 3) 배추가 없는 경우 4) 방문을 한 경우 
        if (ny < 0 || nx < 0 || ny >= b || nx >= a) { continue; }
        if (arr[ny][nx] == 0) continue;
        if (visited[ny][nx] == 1) continue;

        // 위 경우가 모두 아니라면, 새로운 좌표에서 다시 순회 
        dfs(ny, nx);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    // 입력 1. 테스트케이스 개수 
    // 입력 2. 세로, 가로, 배추 개수 
    // 입력 3. for 문 돌면서 각 [y][x] 에 배추 심기 
    cin >> n;
    // 테스트 케이스 만큼 반복 
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        a = 0; b = 0; k = 0;
        memset(arr, 0, sizeof(arr));
        memset(visited, 0, sizeof(visited));
        
        cin >> b >> a >> k;

        for (int i = 0; i < k; i++) {
            
            int cy, cx;
            cin >> cy >> cx;
            arr[cy][cx] = 1; // 배추심기
        }

        for (int i = 0; i < b; i++) {
            for (int j = 0; j < a; j++) {
                // cout << arr[i][j] << " ";
                if (visited[i][j] == 0 && arr[i][j] == 1) {
                    cnt++;
                    dfs(i, j);
                    
                }
            }
            // cout << endl;
        }

        cout << cnt << '\n';
    }
    
}       