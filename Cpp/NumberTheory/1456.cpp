
// 이건 진짜 소수가 몇 개 있는지 구한거고 
/*
int main() {

    int a, b;
    int cnt = 0;
    cin >> a >> b;
    
    int e = 10e7;

    vector<int> arr(e + 1);

    for (int i = 0; i <= e; i++) {
        arr[i] = i; // 소수 판별 배열 선언
    }

    arr[1] = 0;

    for (int i = 2; i <= e; i++) {
        if (arr[i] == 0) { continue; }

        for (int j = i + i; j <= e; j = j + i) {
            arr[j] = 0;
        }
    }

    for (int i = a; i <= b; i++) {
        if (arr[i] != 0) {
            cnt++;
        }
    }
    cout << cnt;
}*/

// 거의 소수 
#include <bits/stdc++.h>
using namespace std;


int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long a, b;
    int cnt = 0;
    cin >> a >> b;
    
    long long e = 1e7;

    vector<long long> arr(e + 1);

    for (int i = 0; i <= e; i++) {
        arr[i] = i; // 소수 판별 배열 선언
    }

    arr[1] = 0;

    for (int i = 2; i <= sqrt(e); i++) {
        if (arr[i] == 0) { continue; }

        for (int j = i + i; j <= e; j = j + i) {
            arr[j] = 0;
        }
    }

    for (long long i = 2; i <= e; i++) {
        if (arr[i] != 0) {
            long long num = i * i;

            while (num <= b) {
                if (num >= a) cnt++;
                if (num > b / i) break;
                num *= i;
            }
        }
    }

    cout << cnt;
}