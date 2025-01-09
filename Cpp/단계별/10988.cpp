#include <bits/stdc++.h>
using namespace std;

int main() {
  // 1. 문자열 입력받는다 
  // 2. 이것과 reverse 한게 같은지 확인한다. 
  // 3. 맞으면 1, 틀리면 0 출력 

  string str;
  cin >> str;
  string str2 = str;
  reverse(str.begin(), str.end());
  
  if (str == str2) {
    cout << 1;
  } else {
    cout << 0;
  }
}
// 기러기 스위스 토마토 별똥별 역삼역 우영우 ?! 같은거를 palindrome 이라고 한다 -> 회문 
// 어떤 문자열이 주어졌을 때 회문인지 체크하는 로직 구현 
// 