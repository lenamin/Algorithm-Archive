// 유클리드 호제법 이용한 최대공약수 구하기 
// 최대공약수 이용해서 최소공배수 구하기 

#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b);

int main() {
    int n;

    cin >> n;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        int gcdn = gcd(a, b);
        cout << a * b / gcdn << '\n';
    }
}

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}