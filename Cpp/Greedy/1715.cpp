#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> cards;

int main() {
    priority_queue<int, vector<int>, greater<int>> pq; // 오름차순 정렬 
    cin >> n;
    // cards.resize(n+1);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;
        pq.push(c);
    }

    while (pq.size() != 1) {
        int c1 = pq.top();
        pq.pop();
        
        int c2 = pq.top();
        pq.pop();
        
        int s = c1 + c2; 
        cnt += s;
        pq.push(s);
    }
    cout << cnt << '\n';
}