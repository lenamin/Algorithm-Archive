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