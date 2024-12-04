#include <bits/stdc++.h>
using namespace std;

char mid;
int flag; // 홀수 갯수 체크하는 플래그 
string ret;

int main() {

  ios::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  vector<int> cnt(26, 0);
  string str;
  cin >> str;

  for (char c : str) {
    cnt[c-'A']++;
  }

  for (int i = cnt.size() - 1; i >= 0; i--) {
    if (cnt[i]) {
      // cout << "(char)i: " << (char)i << endl;
      // cout << "cnt[i]: " << cnt[i] << endl;

      if (cnt[i] & 1) {
        mid = (char)(i+'A');
        flag++;
        cnt[i]--;
      }
      if (flag == 2) {
        cout << "I'm Sorry Hansoo\n";
        return 0;
      }
      for (int j = 0; j < cnt[i]; j += 2) {
        ret = (char)(i+'A') + ret;
        ret += (char)(i+'A');
      }
    } 
  }
  if (mid) {
    ret.insert(ret.begin() + ret.size() / 2, mid);
  }
  cout << ret << '\n';

}