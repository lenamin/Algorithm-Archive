#include <bits/stdc++.h>
using namespace std;

int main() {
  // string 입력받기 
  // 26개 배열 만들기 
  // string 순회하면서 각 배열에 카운트하기 

  string word;
  cin >> word;
  
  vector<int> alph(25, 0);
  vector<char> chr { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

  for (int i = 0; i < word.size(); i++) {
    int idx = word[i] - 'a';
    alph[idx] += 1;
  }
  
  for (int a : alph) {
    cout << a << " ";
  }
}