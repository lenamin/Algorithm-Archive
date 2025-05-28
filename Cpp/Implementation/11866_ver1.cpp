#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> arr;
vector<int> ans;

int main() {
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        arr.push_back(i);
    }

    int idx = 0;
    while (!arr.empty()) {
        idx = (idx + k - 1) % arr.size();  // k번째 사람 찾기
        ans.push_back(arr[idx]);          // 제거된 사람 저장
        arr.erase(arr.begin() + idx);     // 제거
    }

    // 출력
    cout << "<";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i];
        if (i != ans.size() - 1) cout << ", ";
    }
    cout << ">";
}