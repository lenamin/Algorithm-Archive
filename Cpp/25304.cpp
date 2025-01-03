// 영수증 
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n;
    cin >> t;
    cin >> n;
    int sum = 0;

    for (int i = 0; i < n; i++) {
        int p, m;
        cin >> p >> m;
        sum += (p * m);
    }

    if (sum == t) { cout << "Yes"; } else { cout << "No"; }
}