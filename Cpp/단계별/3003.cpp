#include <bits/stdc++.h>
using namespace std;

int main() {
    // 킹 1개, 퀸 1개, 룩 2개, 비숍 2개, 나이트 2개, 폰 8개
    // 1 1 2 2 2 8 이 맞는 것 

    // 음수라면 먼저 제거 
    // 몇개 더하거나 빼야하는지 출력
    vector<int> ch(7);
    vector<int> c = {1, 1, 2, 2, 2, 8};

    for (int i = 0; i < 6; i++) {
        cin >> ch[i];
    }

    for (int i = 0; i < 6; i++) {
        cout << c[i] - ch[i] << " ";
    }
}