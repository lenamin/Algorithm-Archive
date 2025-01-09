#include<bits/stdc++.h>
using namespace std;

vector<int> tr;
int a, b, c;
int s, e;

int main() {
  vector<int> time(101, 0);
  int cnt = 0;

  cin >> a >> b >> c;

  for (int i = 0; i < 3; i++) {
    cin >> s >> e;
    
    for (int j = s; j < e; j++) {
      time[j]++;
    }
  }

  for (int t : time) {
    if (t == 0) {
      continue;
    } else if (t == 1) {
      cnt += (a);
    } else if (t == 2) {
      cnt += (b * t);
    } else if (t == 3) {
      cnt += (c * t);
    } else {
      continue;
    }
  }
  cout << cnt << '\n';
  
}