// 개수세기 

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    int cnt = 0;
    vector<int> arr;

    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }
    cin >> m;

    for (int a : arr) {
        if (a == m) {
            cnt += 1;
        }
    }
    cout << cnt << '\n';
}