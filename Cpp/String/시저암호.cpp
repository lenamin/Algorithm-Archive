// version 1. 

#include <bits/stdc++.h>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    
    for (char c : s) {
        if (c == ' ') { answer.push_back(c); continue; }
        
        /*
        int cc = (int)c;
        if (cc >= 65 && cc <= 90) {// 대문자이면  (굳이 이렇게 ascii 코드로 검사안해도 됨 )
            if (cc + n <= 90) {
                answer.push_back(c + n);    
            } else if (cc + n > 90) {
                answer.push_back(c - 26 + n);
            }
           
        } else if (cc >= 97 && cc <= 122) {
            if (cc + n <= 122) {
                answer.push_back(c + n);
            } else {
                answer.push_back(c - 26 + n);
            }
        }
            }
            */
        char base = isupper(c) ? 'A' : 'a'; // isupper를 쓰면 
        answer.push_back((c - base + n) % 26 + base);
    }
        
    
    return answer;
}