#include <bits/stdc++.h>
using namespace std;

// sort() 대신 버블정렬로 구현해보기 
int main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n - 1; i++) { //
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }

    for (int a : arr) {
        cout << a << '\n';
    }

}