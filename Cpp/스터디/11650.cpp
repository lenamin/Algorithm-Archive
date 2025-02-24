// 3월 1주차 

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> dm;
vector<dm> pt;

int main() {
    int n;
    cin >> n;

    pt.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> pt[i].first >> pt[i].second;
    }

    sort(pt.begin(), pt.end());

    for (auto p : pt) {
        cout << p.first << " " << p.second << '\n';
    }

}