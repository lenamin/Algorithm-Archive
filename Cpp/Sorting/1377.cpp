#include <bits/stdc++.h>
using namespace std;

// 외부 for 문이 몇 번 돌았는지 

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> arr(n); // { 숫자값, 인덱스 }

    for (int i = 0; i < n; i++) {
        cin >> arr[i].first;
        arr[i].second = i; // idx 값 저장 
    }

    sort(arr.begin(), arr.end());

    int ret = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i].second - i > ret) {
            ret = arr[i].second - i;
        }
    }

    cout << ret + 1;

}