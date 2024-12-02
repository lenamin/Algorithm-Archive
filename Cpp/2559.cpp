#include <bits/stdc++.h>
using namespace std;

int m, n;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> m >> n;
  vector<int> arr(m+1, 0);
  vector<int> psum(m+1, 0);
  vector<int> tmp(n+1, 0);

  for (int i = 1; i <= m; i++) {
    int temp;
    cin >> temp;
    arr[i] = temp;
  } 

  for (int i = 1; i <= m+1; i++) {
    // cout << "i: " << i << endl;
    for (int j = 1; j <= n; j++) {
      // cout << "j: " << j << endl;
      if (i+j <= m) {
        tmp[j] = arr[i+j] + tmp[j-1];
        // cout << "temp[" << j << "]: " << tmp[j] << endl;
      } else {
        break;
      }
    }
    psum[i] = tmp[n];
    // cout << "psum은: " << psum[i] << '\n' << '\n';
  }
  
  cout << *max_element(psum.begin(), psum.end());
