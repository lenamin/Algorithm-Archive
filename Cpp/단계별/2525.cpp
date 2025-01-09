// 오븐시계
#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, m, t;
    int additionalHour, additionalMin;
    cin >> h >> m;
    cin >> t;

    if (m + t < 60) {
        cout << h << " " << m + t;
    } else if (m + t >= 60) {
        additionalHour = (m + t) / 60; // 초과되는 시간 (원래시간에다 더해야 함)
        additionalMin = (m + t) % 60; // 초과되는 분 (원래분에다 더해야 함)

        if (h + additionalHour < 24) {
            cout << h + additionalHour << " " << additionalMin;
        }  else {
            cout << h + additionalHour - 24 << " " << additionalMin;
        }
    }
}   