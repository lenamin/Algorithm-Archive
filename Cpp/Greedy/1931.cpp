#include <bits/stdc++.h>
using namespace std;

int n, cnt;
int endT = -1;
vector<pair<int, int>> times;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        times.push_back({t2, t1});
    }

    sort(times.begin(), times.end());
    
    // 다음 시작시간이 앞 종료보다 큰 경우 
    for (int i = 0; i < n; i++) {
        if (times[i].second >= endT) { // 다음 회의 시작이 이전 종료보다 크면 
            endT = times[i].first; // cnt 업데이트 
            cnt += 1;
        }
    }

    cout << cnt << '\n';
    
}