// 에라토스테네스의 체 
#include <bits/stdc++.h>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    vector<int> arr(n + 1);

    for (int i = 0; i <= n; i++) {
        arr[i] = i;
    }

    arr[1] = 0;

    for (int i = 2; i <= sqrt(n); i++) {
        if (arr[i] == 0) continue;
        
        for (int j = i + i; j <= n; j = j + i) {
            arr[j] = 0;
        }
    }

    for (int i = m; i <= n; i++) {
        if (arr[i] != 0) {
            cout << arr[i] << '\n';
        }
    }
}