#include <bits/stdc++.h>

using namespace std;

string solution(string s) {
    string answer = "";
    
    char pc = ' ';
    
    for (int i = 0; i < s.size(); i++) {
        if (pc == ' ') {
            answer += toupper(s[i]);
        } else {
            answer += tolower(s[i]);
        }
        pc = s[i];
    }
    return answer;
}