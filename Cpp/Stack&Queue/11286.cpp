#include <bits/stdc++.h>
using namespace std;

// x가 0이 아니라면 배열에 x 를 추가한다 
// 0이면 절대값 가장 작은 값 출력하고, 그 값을 배열에서 제거 
// 비어있으면 0 출력

int main() {
    int n;
    cin >> n;
    typedef pair<int, int>  nums;
    priority_queue<nums, vector<nums>, greater<nums>> pq; // { 절대값, 원래값}

    for (int i = 0; i < n; i++) {
        int k;
        cin >> k; 

        if (k != 0) {
            pq.push({abs(k), k});
        } else if (k == 0) {
            if (!pq.empty()) {
                pair<int, int> t = pq.top();
                cout << t.second << '\n';
                pq.pop();
            } else { // pq 비어있으면 
                cout << 0 << '\n';
            }
        }
    }
}