#include <bits/stdc++.h>
using namespace std;

long long a, b, c;
long long answer = 1;


int main() {
    cin >> a >> b >> c;
    long long base = a % c;
    
    while (b > 0) {
        if (b & 1) {
            answer = (answer * base % c);
        }
        base = (base * base) % c;
        b /= 2;
    }

    cout << answer << '\n';
}