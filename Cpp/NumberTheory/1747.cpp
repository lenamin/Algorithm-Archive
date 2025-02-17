// 소수&팰린드롬

#include <bits/stdc++.h>
using namespace std;

long long e = 1e7;
bool isPal(int a);

int main() {
    // 에라토스테네스의 체 먼저 구현해보자 
    int n;
    cin >> n;

    vector<int> arr(e + 1);

    for (int i = 0; i < e+1; i++) {
        arr[i] = i;
    }
    arr[1] = 0;
    
    for (int i = 2; i * i <= e; i++) {

        if (arr[i] == 0) continue;

        for (int j = i + i; j < e; j = i + j) {
            arr[j] = 0; // 배수들에 대해 모두 소수 없애기 
        }
    }

    for (int i = n; i <= e; i++) {
        if (arr[i] >= n && isPal(arr[i]) && arr[i] != 0) {
            cout << i << '\n';
            break;
        }
    }
}

bool isPal(int a) {
    string str = to_string(a);
    string rev = str;
    reverse(str.begin(), str.end());
    
    return (str == rev);
}