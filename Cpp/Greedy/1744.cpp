// 수 묶기
#include <bits/stdc++.h>
using namespace std;

int main() {
    // 음수, 1보다 큰 수, 1, 0 으로 나눠서 저장하자 
    // vector<int> neg;
    // vector<int> nat;
    vector<int> zn; // 0
    vector<int> on; // 1
    priority_queue<int> descPq; // 양수 넣기위한 우선순위 큐
    priority_queue<int, vector<int>, greater<int>> ascPq; // 음수 넣기 위한 우선순위 큐 
    
    int n;
    int sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        if (t == 0) zn.push_back(t);
        if (t == 1) on.push_back(t);
        if (t > 1) { 
            descPq.push(t);
        }
        if (t < 0) {
            ascPq.push(t);
        }
    }

    // 양수가 2개 이상이면 제일 큰 값 서로 곱하기 -> 이걸 pq에 원소 하나 남을 때 까지 반복
    while (descPq.size() > 1) {
        int m1 = descPq.top();
        descPq.pop();

        int m2 = descPq.top();
        descPq.pop();

        sum += m1 * m2;
    }
    // } 
    
    // if (neg.size() > 1) {
    while (ascPq.size() > 1) {
        int m1 = ascPq.top();
        ascPq.pop();

        int m2 = ascPq.top();
        ascPq.pop();

        sum += m1 * m2;
    }
    // }

    if (zn.size() > 0 && ascPq.size() >= 1) {
        // cout << "실행됨";
        sum += zn[0] * ascPq.top();
        ascPq.pop();
    }

    if (!descPq.empty()) {
        int k = descPq.top();
        descPq.pop();
        sum += k;
    }

    if (!ascPq.empty()) {
        int k = ascPq.top();
        ascPq.pop();
        sum += k;
    }

    sum += on.size();
    cout << sum << '\n';
}