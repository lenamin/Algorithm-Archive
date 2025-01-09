// 공바꾸기 

#include <bits/stdc++.h>
using namespace std;

static int n, m;
static vector<int> baskets;

int main() {
    
    cin >> n >> m;
    
    // 일단 인덱스 + 1로 초기화 
    for (int i = 1; i <= n; i++) {
        baskets.push_back(i);
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        swap(baskets[a-1], baskets[b-1]);
    }

    for (int b : baskets) {
        cout << b << " ";
    }
}