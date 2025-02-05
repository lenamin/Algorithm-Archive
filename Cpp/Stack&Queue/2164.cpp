// 카드 2
#include <bits/stdc++.h>
using namespace std;

queue<int> q;

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        q.push(i);
    }

    while (q.size() > 1) {
        // 버리기 
        q.pop();

        // 젤 위에 있는 걸 젤 뒤로 넣기 
        int a = q.front();
        q.pop();
        q.push(a);
    }

    cout << q.front(); 
}