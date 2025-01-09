// 공 넣기
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> b(n+1, 0);

    for (int i = 1; i <= m; i++) {
        int s, e, ball;

        cin >> s >> e >> ball;
        
        fill(b.begin() + s, b.begin() + e + 1, ball);

    }

    for (int i = 1; i <= n; i++) {
        cout << b[i] << " ";
    }   
}