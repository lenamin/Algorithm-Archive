#include <bits/stdc++.h>
using namespace std;

string dt(int a) {
    if (a == 0) return "";
    int m = a % 3;
    int n = a / 3;
    
    char c = m + '0';
    return dt(n) + c;
}

int solution(int n) {
    int answer = 0;
    
    string s = dt(n);
    
    for (int i = 0; i < s.size(); i++) {
        int digit = s[i] - '0';
        answer += digit * pow(3, i);
    }
  
    return answer;
}