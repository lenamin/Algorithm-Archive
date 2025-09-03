// 벌집
#include <bits/stdc++.h>
using namespace std;

int main() {
    // 첫번째 : 1 [0]
    // 두번째 : 2 ~ 7 (+6)
    // 세번째 : 8 ~ 19  (+12)
    // 네번째 : 20 ~ 37  (+ 18)

    long long k;
    cin >> k;
    
    if (k == 1) { 
        cout << 1 << '\n'; 
        return 0; 
    }

    long long layer = 1;
    long long end = 1;

    while (k > end) {

        end = end + 6 * layer;
        layer++;
    }
    cout << layer << '\n';
}