// 바구니 뒤집기

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> arr(n+1);

    for (int i = 1; i <= n; i++) {
        arr[i] = i;
    }

    for (int i = 0; i < m; i++) {
        int t1, t2;
        cin >> t1 >> t2;

        reverse(arr.begin() + t1, arr.begin() + t2 + 1);
    }

    for (int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    }
}