#include <bits/stdc++.h>
using namespace std;

int n, l;
typedef pair<int, int> node;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> l;

    deque<node> dq;

    for (int i = 0; i < n; i++) {
        int now;
        cin >> now;

        while (dq.size() && dq.back().first > now) {
            dq.pop_back();
        }
        dq.push_back(node(now, i)); // 범위 밖이면 제거 
        
        if (dq.front().second <= i - l) {
            dq.pop_front();
        }

        cout << dq.front().first << ' ';
    }
}