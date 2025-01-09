#include <bits/stdc++.h>
using namespace std;

#define ALP 26
#define ROT 13

int main() {
  // 문자열 입력받기 
  // 13글자씩 밀어서 만든다 
  // 대문자 혹은 소문자에만 적용할 것 
  // 띄어쓰기 혹은 숫자는 그대로 

  // 입력받은 문자열을 순회하면서 
  // 하나의 char 씩 13자리 뒤에 있는 ascii 코드 값의 문자를 받아와 새 배열에 넣는다. 
  // 다 되면 출력 

  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string str;
  getline(cin, str);

  string nStr;
  
  for (int i = 0; i < str.size(); i++) {
    int ascii = (int)str[i];
    
    if (ascii < 65) {
      nStr.push_back(str[i]);
    } 
    // 대문자인 경우 -> 인덱스 구할 때 65에서 i를 더해서 구함  
    else if (ascii >= 65 && ascii < 97) { 
      int idx = (ascii - 65 + ROT) % ALP;
      // cout << "(대문자)지금 나의 idx: " << idx << ", " << (char)idx << endl;
      nStr.push_back((char)(idx + 65));
    } 
    // 소문자인경우 -> 인덱스 구할 때 97에서 i를 더해서 구함 
    else if (ascii >= 97) {
      int idx = (ascii - 97 + ROT) % ALP;
      // cout << "(소문자)지금 나의 idx: " << idx << ", " << (char)idx << endl;
      nStr.push_back((char)(idx + 97));
    }
  }

  cout << nStr;
}