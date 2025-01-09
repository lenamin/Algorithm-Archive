#include <bits/stdc++.h>
using namespace std;

vector<int> arr(26,0);
string temp;
char f;
bool isFind = false;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;  
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> temp;
    f = temp[0];
    arr[f - 'a']++;
  }

  for (int i = 0; i < arr.size(); i++) {
    if (arr[i] >= 5) {
      isFind = true;
      int a = 97 + i;
      cout << (char)a;
    } 
  }
  if (!isFind) {
    cout << "PREDAJA";
  }

}