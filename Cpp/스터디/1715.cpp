// 카드 정렬하기 (우선순위 큐/그리디)
#include <bits/stdc++.h>
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq; // 우선순위 큐 오름차순으로 
int sum, cnt;
vector<int> v;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k; 
        pq.push(k);
    }

    while (pq.size() > 1) {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        int temp = a + b;
        pq.push(temp);
        sum += temp;
    }

    cout << sum << '\n';
}