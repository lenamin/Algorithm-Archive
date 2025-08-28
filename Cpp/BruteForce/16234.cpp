#include <bits/stdc++.h>
using namespace std;

int n, l, r;
int ret;

vector<vector<int>> arr;
vector<vector<int>> visited;

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {-1, 0, 1, 0};

vector<pair<int, int>> nb;

void dfs(int y, int x) {
    
    visited[y][x] = 1; // 방문처리 
    nb.push_back({y, x}); // nb에 국경이 열리는 나라들 모으기, 이건 백트래킹할 때 초기화할 것 ! 

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue; // 유효성 체크 
        if (visited[ny][nx] == 1) continue; // 기방문했으면 넘어가기 

        int diff = abs(arr[y][x] - arr[ny][nx]);
        
        if (diff >= l && diff <= r) { // 국경선 열려있는지 체크 
            dfs(ny, nx);  
        }    
    }
}

int main() {
    cin >> n >> l >> r;

    arr.resize(n, vector<int>(n, 0));
    visited.resize(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int k = 0;
            cin >> k;
            arr[i][j] = k;
        }
    }
    // 두 나라의 인구차이가 l명이상 r명 이하이면 -> 이동이 가능함 
    // 인접한 나라 -> 인접한 것 

    ret = 0;
    
    while (true) {
        bool moved = false;

        visited.clear();
        visited.resize(n, vector<int> (n, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (!visited[i][j]) {
                    nb.clear();
                    dfs(i, j);
                    
                    // 하나의 연합의 총합과 개수 구하기 
                    int cnt = nb.size();
                    int sum = 0;
                    if (cnt > 1) moved = true;

                    for (auto p : nb) {
                        sum += arr[p.first][p.second];    
                    }

                    int avg = sum / cnt;
                    
                    for (auto p : nb) {
                        // cout << " 여기 실행되고 있나? " << '\n';
                        arr[p.first][p.second] = avg;
                    }

                    // cout << "------ 인구이동 완료 -------" << '\n';
                    
                    // for (int i = 0; i < n; i++) {
                    //     for (int j = 0; j < n; j++) {
                    //         cout << arr[i][j] << " ";
                    //     }
                    //     cout << '\n';
                    // }   
                }
            }
        }
        if (!moved) { 
            break;
        } else {
            ret++;
        }
    }
    cout << ret << '\n';
}