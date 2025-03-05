// 색종이 
// 컴퓨터처럼 생각하기 
// 좌표를 구해서 넓이를 계산하려고 하니까 어려웠던 것 
// 사람처럼 생각하지 않기! 

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    vector<pair<int, int>> d;
    vector<vector<bool>> isC(100, vector<bool>(100, false));
    int rtn = 0;

    cin >> n;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        d.push_back({x, y});
    }   

    for (auto a : d) {
        int x = a.first;
        int y = a.second;
        
        for (int i = x; i < x + 10; i++) {
            for (int j = y; j < y + 10; j++) {
                if (!isC[i][j]) {
                    isC[i][j] = true;
                    rtn++;
                }
                
            }
        }
    }

    cout << rtn << '\n';
    
}