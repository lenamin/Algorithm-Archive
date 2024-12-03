#include <bits/stdc++.h>
using namespace std;

int n, k;

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    map<string, int> mp {};
    int cnt = 1;
    cin >> k;
    for (int j = 0; j < k; j++) {
      
      int m;
      string tmp, kind;
      cin >> tmp >> kind;
      mp[kind]++;
    }
    for ( auto m : mp ) {
      cnt *= m.second + 1;
    }
    cout << cnt - 1 << '\n';
  }
}