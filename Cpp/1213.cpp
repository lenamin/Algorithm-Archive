#include <bits/stdc++.h>
using namespace std;

string str;
vector<char> arr;

bool isPal(vector<char> a) {
  vector<char> tmp = a;

  reverse(tmp.begin(), tmp.end());
  
  if (tmp == a) {
    return true;
  } else {
    return false;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  cin >> str;

  for (char c : str) {
    arr.push_back(c);
  }

  do {
    if (!isPal(arr)) {
      continue;
    } else { 
      for (auto a : arr) {
        cout << a;
      }
      cout << '\n';
     }
  } while (next_permutation(arr.begin(), arr.end()));
}