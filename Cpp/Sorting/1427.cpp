// 선택정렬 
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    vector<int> arr(s.size());

    for (int i = 0; i < s.size(); i++) {
        
        arr[i] = s[i] - '0';
    }

    // 최댓값 찾기 

    for (int i = 0; i < s.length(); i++) {
        int m = i; // 최댓값을 넣을 인덱스 
        
        for (int j = i + 1; j < s.length(); j++) {
            if (arr[j] > arr[m]) {
               m = j;
            }
        }

        if (arr[i] < arr[m]) {
            swap(arr[i], arr[m]);
        }
    }
    for (int a : arr) {
        cout << a;
    }
}