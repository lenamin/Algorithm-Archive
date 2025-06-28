#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> picked;

void backtrack(int start, int depth) {
    if (depth == m) {
        for (auto p : picked) { cout << p << " "; }
        cout << '\n';
        return;
    }

    for (int i = start; i <= n; i++) {
        picked.push_back(i);
        backtrack(i + 1, depth + 1);
        picked.pop_back();
    }
}

int main() {
    cin >> n >> m;

    backtrack(1, 0);
}