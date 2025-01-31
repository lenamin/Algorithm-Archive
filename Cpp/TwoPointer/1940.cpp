#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, target;
    
    cin >> n;
    cin >> target;

    vector<int> cost(n);

    for (int i = 0; i < n; i++) {
        cin >> cost[i];
    }
    
    sort(cost.begin(), cost.end());

    int cnt = 0;
    int i = 0;
    int j = cost.size() - 1;
    
    // for (int c : cost) {
    //     cout << c << " ";
    // }

    while (i < j) {
        if ((cost[i] + cost[j]) == target) {
            i++;
            j--;
            cnt++;
        } else if ((cost[i] + cost[j]) > target) {
            j--;
        } else if ((cost[i] + cost[j]) < target) {
            i++;
        }
    }

    cout << cnt;
}