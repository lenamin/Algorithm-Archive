#include <bits/stdc++.h>
using namespace std;

int n;
int cp = 0;
int cm = 0;
int cz = 0;

vector<vector<int>> arr;

bool checkSame(int x, int y, int len) {
    int init = arr[x][y];
    bool isSame = true;

    if (len == 1) { return true; }

    for (int i = x; i < x + len; i++) {
        for (int j = y; j < y + len; j++) {
            if (init != arr[i][j]) {
                isSame = false;
                return false;
            } else {
                isSame = true;
            }
        }
    }
    return isSame;
}

void solve(int x, int y, int len) {

    if (!checkSame(x, y, len)) {

        int newLen = len / 3;

        for (int dx = 0; dx < 3; dx++) {
            for (int dy = 0; dy < 3; dy++) {
                solve(x + dx * newLen, y + dy * newLen, newLen);
            }
        }

    } else {
        // 모두 같으면 
        if (arr[x][y] == 1) { cp++; }
        else if (arr[x][y] == -1) { cm++; }
        else if (arr[x][y] == 0) { cz++; }
    }
}

int main() {
    cin >> n; 

    arr.resize(n, vector<int> (n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int tmp;
            cin >> tmp;
            arr[i][j] = tmp; 
        }
    }

    solve(0, 0, n);
    
    cout << cm << '\n' << cz << '\n' << cp << '\n';


}