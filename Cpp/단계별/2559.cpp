// 시간 초과 난 코드 O(mn) 이라 시간초과 남 
/*
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
}*/

#include <bits/stdc++.h>
using namespace std;

int n, k, temp, ret = -1000004;
int main() {
  cin >> n >> k;
  vector<int> psum(n+1, 0);

  for (int i = 1; i <= n; i++) {
    cin >> temp;
    psum[i] = psum[i-1] + temp;
  }

  for (int i = k; i <= n; i++) {
    ret = max(ret, psum[i] - psum[i-k]);
  }

  cout << ret << '\n';
  return 0;
}