#include <bits/stdc++.h>
using namespace std;

int main() {
    
    while (true) {
        vector<int> n;
        int a, b, c;
        cin >> a >> b >> c;
        n.push_back(a);
        n.push_back(b);
        n.push_back(c);
        sort(n.begin(), n.end());
        
        if (a == 0 &&  b == 0 && c == 0) break;

        if (n[0] * n[0] + n[1] * n[1] == n[2] * n[2]) cout << "right" << "\n";
        else cout << "wrong" << "\n";
    }
}