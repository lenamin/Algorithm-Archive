#include <bits/stdc++.h>
using namespace std;

int n, k;
queue<int> q;
vector<int> ans;

int main() {
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        q.push(i);
    }

    while (!q.empty()) {
        for (int i = 0; i < k - 1; i++) {
            int a = q.front();
            q.pop();
            q.push(a);
        }

        int m = q.front();
        q.pop();
        ans.push_back(m);
    }

    cout << "<";
    for (int i = 0; i < n - 1; i++) {
        cout << ans[i] << ", ";
    }
    cout << ans[n-1] << ">" << '\n';
}