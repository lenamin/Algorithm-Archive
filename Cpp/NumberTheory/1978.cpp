// 소수 찾기 

#include <bits/stdc++.h>

using namespace std;
int cnt;
bool checkPri(int k) {
    int ret = 0;
    for (int i = 1; i <= k; i++) {
        if (k % i == 0) {
            ret++;
        }
    }
    if (ret == 2) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        if (k != 1 && checkPri(k)) {
            cnt++;
        }
    }
    cout << cnt << '\n';
}