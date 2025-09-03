#include <bits/stdc++.h>
using namespace std;

int n; // n 명 참가자수 전체
int s, m, l, xl, xxl, xxxl;
int t; // 티셔츠 한묶음에 t 개
int p; // 연필 한묶음에 p개 
vector<int> ts;

int main() {
    cin >> n;
    cin >> s >> m >> l >> xl >> xxl >> xxxl;
    cin >> t >> p;

    ts.push_back(s);
    ts.push_back(m);
    ts.push_back(l);
    ts.push_back(xl);
    ts.push_back(xxl);
    ts.push_back(xxxl);

    int ttotal = 0;
    
    for (int i = 0; i < 6; i++) {
        if (ts[i] == 0) { 
            ttotal += 0;
        }
        if (ts[i] % t == 0) {
            ttotal += (ts[i] / t);
        } else {
            ttotal += (ts[i] / t + 1);
        }
    }
    cout << ttotal << '\n';

    cout << n / p << " " << n % p << '\n';
}