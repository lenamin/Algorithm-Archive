#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) { return a; } // b가 0이면 a가 최대공약수 
    else {
        return gcd(b, a % b); // 재귀호출: b와 a % b로 다시 계산 
    }
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

vector<int> solution(int n, int m) {
    vector<int> answer(2);

    answer[0] = gcd(n, m);
    answer[1] = lcm(n, m);
    
    return answer;
}