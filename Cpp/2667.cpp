// 단지번호붙이기 
#include <bits/stdc++.h>
using namespace std;

int n;
int arr[32][32];
int visited[32][32];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int cnt = 0; // 각 단지내 수 카운트 용 
int cc = 0; // connected componenets 개수 세는 용도
vector<int> ret;

void dfs(int y, int x) {
    cnt += 1;
    visited[y][x] = 1; // 현재 노드 방문처리 

    // 이제 (ny, nx) 계산해서 하나씩 주변에 있는지 체크해서 방문할 것 
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (visited[ny][nx] == 1) continue;
        if (arr[ny][nx] == 0) continue;
        
        dfs(ny, nx);
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        
        for (int j = 0; j < n; j++) {
            arr[i][j] = s[j] - '0';
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cnt = 0;
            if (arr[i][j] == 1 && visited[i][j] == 0) { 
                cc++;
                dfs(i, j);
            }
            if (cnt != 0) {
                ret.push_back(cnt);
            }
        }
    }

    sort(ret.begin(), ret.end());   
    
    cout << cc << '\n';

    for ( auto r : ret) {
        cout << r << '\n';
    }
    
}