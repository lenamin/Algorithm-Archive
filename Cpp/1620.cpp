#include <bits/stdc++.h>
#include <cctype>
using namespace std;

int n, k;
string temp;
map<int, string>p;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  cin >> n >> k;
  
  for (int i = 1; i <= n; i++) {
    cin >> temp;
    p.insert({i, temp});
  }

  for (int i = 0; i < k; i++) {
    string a;
    cin >> a;

    if (isdigit(a[0])) {
      int m = atoi(a.c_str());
      string key = p[m];
      cout << key << '\n';
    } 
    if (typeid(a) == typeid(string)) {
      for (const auto& pk : p) {
        if (pk.second == a) {
          cout << pk.first << '\n';
        }
      }
    } 
  }
  return 0;
}