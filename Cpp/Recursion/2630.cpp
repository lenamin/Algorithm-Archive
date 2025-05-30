#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> arr;
int bcnt;
int wcnt;

bool check(int x, int y, int n) {
    int prv = arr[x][y]; // 시작값 기억 prev에 

    for (int i = x; i < x + n; i++) {
        for (int j = y; j < y + n; j++) {
            if (arr[i][j] != prv) { 
                return false;
            } 
        }
    }
    
    return true;
}

void divide(int x, int y, int n) {
    // cout << " divide 실행됨 ==== " << '\n';
    if (check(x, y, n)) {
        if (arr[x][y] == 1) { bcnt++; }
        else if (arr[x][y] == 0) { wcnt++; }
        return;
    } else {
        divide(x, y, n/2);
        divide(x + n/2, y, n/2);
        divide(x, y + n/2, n/2);
        divide(x + n/2, y + n/2, n/2);    
    }
    
}

int main() {
    int n;
    cin >> n;

    arr.resize(n + 1, vector<int>(n + 1));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int a;
            cin >> a;
            arr[i][j] = a;
        }
    }

    divide(0, 0, n);

    cout << wcnt << '\n' << bcnt << '\n';
    

}