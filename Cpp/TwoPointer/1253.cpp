#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    int cnt = 0;

    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    for (int k = 0; k < n; k++) {
        int i = 0;
        int j = n - 1; // k-1 로 했을 때 0, 0, 0, 0 예시에서 반례가 생겨버림 
        long long target = arr[k];
        
        while (i < j) {
            
            if ((arr[i] + arr[j]) == target) {
                if (i == k) { i++; }
                else if (j == k) { j--; }
                else if (i != k && j != k) { 
                    cnt++;
                    break;
                } 
            } else if ((arr[i] + arr[j]) < target) {
                i++;
            } else if ((arr[i] + arr[j]) > target) {
                j--;
            }
        }
    }
    cout << cnt;
}